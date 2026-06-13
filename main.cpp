#include "Libraries/Movie/Movie.hpp"
#include "Libraries/Series/Series.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Exception/InvalidRatingException/InvalidRatingException.hpp"
#include "Exception/EmptyFieldException/EmptyFieldException.hpp"
#include "Exception/InvalidNumberException/InvalidNumberException.hpp"
#include "Exception/DivideByZeroException/DivideByZeroException.hpp"

using namespace std;

void loadFromFile(vector<Video*>& catalog, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }
    string line;
    Series* currentSeries = nullptr;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ',');

        // Each record is validated separately, so one bad line does not abort
        // the whole load. The base class "exception" catches every kind of
        // exception (our own classes and the ones thrown by stoi).
        try {
            if (type == "MOVIE") {
                string id, name, genre, lengthStr;
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, lengthStr, ',');
                getline(ss, genre, ',');
                int length = stoi(lengthStr);

                Movie movie(id, name, length, genre);
                movie.validate();
                catalog.push_back(new Movie(movie));
                currentSeries = nullptr;

            } else if (type == "SERIES") {
                string id, name, genre, lengthStr;
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, lengthStr, ',');
                getline(ss, genre, ',');
                int length = stoi(lengthStr);

                Series series(id, name, length, genre);
                series.validate();
                Series* s = new Series(series);
                catalog.push_back(s);
                currentSeries = s;

            } else if (type == "SEASON") {
                string seasonStr;
                getline(ss, seasonStr, ',');
                int seasonNum = stoi(seasonStr);
                if (seasonNum <= 0) {
                    throw InvalidNumberException("season", seasonNum);
                }
                if (currentSeries != nullptr) {
                    currentSeries->addSeason(Season(seasonNum));
                }

            } else if (type == "EPISODE") {
                string id, title, lengthStr, genre;
                getline(ss, id, ',');
                getline(ss, title, ',');
                getline(ss, lengthStr, ',');
                getline(ss, genre, ',');
                int length = stoi(lengthStr);

                Episode episode(id, title, length, genre);
                episode.validate();
                if (currentSeries != nullptr) {
                    currentSeries->addEpisodeToLastSeason(episode);
                }
            }
        } catch (exception& e) {
            cout << "Skipping invalid record: " << e.what() << endl;
        }
    }
}

int main() {
    vector<Video*> catalog;

    int option;
    do {
        cout << "\n=== Streaming Service ===" << endl;
        cout << "1. Load data file" << endl;
        cout << "2. Show videos by rating or genre" << endl;
        cout << "3. Show episodes of a series by rating" << endl;
        cout << "4. Show movies by rating" << endl;
        cout << "5. Rate a video" << endl;
        cout << "6. Exit" << endl;
        cout << "Option: ";
        cin >> option;

        switch(option) {
            case 1: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                try {
                    loadFromFile(catalog, filename);
                    cout << "File loaded successfully." << endl;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 2: {
                cout << "1. Filter by genre" << endl;
                cout << "2. Filter by rating" << endl;
                cout << "Option: ";
                int subOption;
                cin >> subOption;
                if (subOption == 1) {
                    string genre;
                    cout << "Enter genre: ";
                    cin >> genre;
                    for (Video* v : catalog) {
                        if (v->getGenre() == genre) {
                            v->show();
                        }
                    }
                } else if (subOption == 2) {
                    float rating;
                    cout << "Enter minimum rating: ";
                    cin >> rating;
                    for (Video* v : catalog) {
                        try {
                            if (v->getAverageRating() >= rating) {
                                v->show();
                            }
                        } catch (DivideByZeroException& e) {
                            // Unrated video does not meet a rating filter; skip it.
                        }
                    }
                }
                break;
            }
            case 3: {
                string seriesName;
                float rating;
                cout << "Enter series name: ";
                cin.ignore();
                getline(cin, seriesName);
                cout << "Enter minimum rating: ";
                cin >> rating;
                for (Video* v : catalog) {
                    Series* s = dynamic_cast<Series*>(v);
                    if (s != nullptr && s->getName() == seriesName) {
                        s->showEpisodesByRating(rating);
                    }
                }
                break;
            }
            case 4: {
                float rating;
                cout << "Enter minimum rating: ";
                cin >> rating;
                for (Video* v : catalog) {
                    Movie* m = dynamic_cast<Movie*>(v);
                    if (m != nullptr) {
                        try {
                            if (m->getAverageRating() >= rating) {
                                m->show();
                            }
                        } catch (DivideByZeroException& e) {
                            // Unrated movie does not meet a rating filter; skip it.
                        }
                    }
                }
                break;
            }
            case 5: {
                string title;
                float rating;
                cout << "Enter video title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter rating (1-5): ";
                cin >> rating;
                for (Video* v : catalog) {
                    if (v->getName() == title) {
                        try {
                            *v += rating;
                            cout << "Rating added." << endl;
                        } catch (InvalidRatingException& e) {
                            cout << e.what() << endl;
                        }
                    }
                }
                break;
            }
            case 6: {
                cout << "Goodbye!" << endl;
                break;
            }
            default: cout << "Invalid option. Try again." << endl;
        }
    } while (option != 6);

    for (Video* v : catalog) {
        delete v;
    }
    catalog.clear();

    return 0;
}
