#include "Series.hpp"
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
            total += e.getAverageRating();
            count++;
        }
    }
    if (count == 0) return 0.0;
    return total / count;
}

void Series::show() const {
    cout << "[Series] " << name << " | Genre: " << genre
         << " | Length: " << length << " min | Rating: " << getAverageRating() << endl;
}

void Series::showEpisodesByRating(float rating) const {
    for (const Season& s : seasons) {
        for (const Episode& e : s.getEpisodes()) {
            if (e.getAverageRating() >= rating) {
                e.show();
            }
        }
    }
}
