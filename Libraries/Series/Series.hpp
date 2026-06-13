#ifndef SITUATEDPROBLEM_SERIES_HPP
#define SITUATEDPROBLEM_SERIES_HPP

#include "../Video/Video.hpp"
#include "../Season/Season.hpp"

using namespace std;

class Series : public Video {
private:
    vector<Season> seasons;
public:
    Series(const string& id, const string& name, int length, const string& genre);
    ~Series();
    void addSeason(const Season& season);
    void addEpisodeToLastSeason(const Episode& episode);
    const vector<Season>& getSeasons() const;
    void showEpisodesByRating(float rating) const;
    float getAverageRating() const override;
    void show() const override;
};

#endif //SITUATEDPROBLEM_SERIES_HPP
