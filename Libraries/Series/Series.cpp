#include "Series.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"
#include <iostream>
using namespace std;

Series::Series(const string &id, const string &name, int length, const string &genre) : Video(id, name, length, genre) {}

Series::~Series() {};

vector<Episode> Series::getEpisodes() const {
    return this->episodes;
}

void Series::addEpisode(const Episode &episode) {
    this->episodes.push_back(episode);
}

void Series::show() const {
    cout << "[Series] " << this->name  << " | Genre: " << this->genre
         << " | Length: " << this->length << " min" << " | Rating: ";
    try {
        cout << getAverageRating();
    } catch (DivideByZeroException& e) {
        cout << "Not rated";
    }
    cout << endl;
}

void Series::showEpisodesByRating(float rating) const {
    for (const Episode& e : this->episodes) {
        try {
            if (e.getAverageRating() >= rating) {
                e.show();
            }
        } catch (DivideByZeroException& ex) {
            // An episode with no ratings does not meet a rating filter; skip it.
        }
    }
}

void Series::validate() const {
    Video::validate();
    for (const Episode& e : this->episodes) {
        e.validate();
    }
}
