#include "Movie/Movie.hpp"
#include "Series/Series.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Exception/InvalidRatingException/InvalidRatingException.hpp"

using namespace std;

// Reads the data from file
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

        if (type == "MOVIE") {
            string id, name, genre;
            int length;
            string lengthStr;

            getline(ss,id, ',');
            getline(ss,name, ',');
            getline(ss,lengthStr, ',');
            getline(ss,genre, ',');

            length = stoi(lengthStr);

            catalog.push_back(new Movie(id, name, length, genre));
            currentSeries = nullptr;
        } else if (type == "SERIES") {
            string id, name, genre, lengthStr;
            int length;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, lengthStr, ',');
            getline(ss, genre, ',');

            length = stoi(lengthStr);

            Series* s = new Series(id, name, length, genre);
            catalog.push_back(s);
            currentSeries = s;
        } else if (type == "EPISODE") {
            string title, seasonStr;
            int season;

            getline(ss, title, ',');
            getline(ss, seasonStr, ',');
            season = stoi(seasonStr);

            if (currentSeries != nullptr) {
                currentSeries->addEpisode(Episode(title, season));
            }
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
                break;}
            case 2: {cout << "1. Filter by genre" << endl;
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
                        if (v->getAverageRating() >= rating) {
                            v->show();
                        }
                    }
                }
                break;}
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
                    if (m != nullptr && m->getAverageRating() >= rating) {
                        m->show();
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