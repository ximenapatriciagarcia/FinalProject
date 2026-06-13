#ifndef SITUATEDPROBLEM_EPISODE_HPP
#define SITUATEDPROBLEM_EPISODE_HPP

#include <string>
#include <vector>
using namespace std;

class Episode {
private:
    string title;
    int season;
    vector<float> ratings;
public:
    Episode(const string& t, int s);
    ~Episode();
    string getTitle() const;
    int getSeason() const;
    float getAverageRating() const;
    Episode& operator+=(float rating);
    void show() const;
};

#endif //SITUATEDPROBLEM_EPISODE_HPP