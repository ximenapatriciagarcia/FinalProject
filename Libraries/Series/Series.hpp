#ifndef SITUATEDPROBLEM_SERIES_HPP
#define SITUATEDPROBLEM_SERIES_HPP

#include "Video.hpp"
#include "Episode.hpp"

class Series : public Video {
private:
    vector<Episode> episodes;
public:
    Series(const string& id, const string& name, int length, const string& genre);
    ~Series();
    void addEpisode(const Episode& episode);
    vector<Episode> getEpisodes() const;
    void showEpisodesByRating(float rating) const;
    void show() const override;
};
#endif //SITUATEDPROBLEM_SERIES_HPP