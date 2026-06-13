#ifndef SITUATEDPROBLEM_VIDEO_HPP
#define SITUATEDPROBLEM_VIDEO_HPP

#include <vector>
#include <string>
#include "InvalidRatingException/InvalidRatingException.hpp"
using namespace std;

class Video {
protected:
    string id;
    string name;
    int length;
    string genre;
    vector<float> ratings;
public:
    Video(const string& id, const string& name, int length, const string& genre);
    virtual ~Video();
    virtual void show() const = 0;
    string getId() const;
    string getName() const;
    int getLength() const;
    string getGenre() const;
    float getAverageRating() const;
    Video& operator+=(float rating);
};

#endif //SITUATEDPROBLEM_VIDEO_HPP