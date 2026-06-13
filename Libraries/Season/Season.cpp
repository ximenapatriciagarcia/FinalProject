#include "Season.hpp"
#include <iostream>
using namespace std;

Season::Season(int number) : number(number) {}

void Season::addEpisode(const Episode& episode) {
    episodes.push_back(episode);
}

const vector<Episode>& Season::getEpisodes() const {
    return episodes;
}

int Season::getNumber() const {
    return number;
}

void Season::show() const {
    cout << "  Season " << number << ":" << endl;
    for (const Episode& e : episodes) {
        e.show();
    }
}
