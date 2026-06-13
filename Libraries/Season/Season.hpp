#ifndef SEASON_HPP
#define SEASON_HPP

#include "../Episode/Episode.hpp"
#include <vector>

class Season {
private:
    int number;
    vector<Episode> episodes;
public:
    Season(int number);
    void addEpisode(const Episode& episode);
    const vector<Episode>& getEpisodes() const;
    int getNumber() const;
    void show() const;
};

#endif //SEASON_HPP
