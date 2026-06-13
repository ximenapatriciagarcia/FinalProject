#include "Series.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"
#include <iostream>
using namespace std;

Series::Series(const string& id, const string& name, int length, const string& genre)
    : Video(id, name, length, genre) {}

Series::~Series() {}

void Series::addSeason(const Season& season) {
    seasons.push_back(season);
}

void Series::addEpisodeToLastSeason(const Episode& episode) {
    if (!seasons.empty()) {
        seasons.back().addEpisode(episode);
    }
}

const vector<Season>& Series::getSeasons() const {
    return seasons;
}

float Series::getAverageRating() const {
    int count = 0;
    float total = 0.0;
    for (const Season& s : seasons) {
        for (const Episode& e : s.getEpisodes()) {
            try {
                total += e.getAverageRating();
                count++;
            } catch (DivideByZeroException& ex) {
                // An episode with no ratings is not counted in the average.
            }
        }
    }
    if (count == 0) {
        throw DivideByZeroException();
    }
    return total / count;
}

void Series::show() const {
    cout << "[Series] " << name << " | Genre: " << genre
         << " | Length: " << length << " min | Rating: ";
    try {
        cout << getAverageRating();
    } catch (DivideByZeroException& e) {
        cout << "Not rated";
    }
    cout << endl;
}

void Series::showEpisodesByRating(float rating) const {
    for (const Season& s : seasons) {
        for (const Episode& e : s.getEpisodes()) {
            try {
                if (e.getAverageRating() >= rating) {
                    e.show();
                }
            } catch (DivideByZeroException& ex) {
                // An episode with no ratings does not meet a rating filter; skip it.
            }
        }
    }
}

void Series::validate() const {
    Video::validate();
    for (const Season& s : seasons) {
        for (const Episode& e : s.getEpisodes()) {
            e.validate();
        }
    }
}
