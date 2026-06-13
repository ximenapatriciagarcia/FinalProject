#ifndef SITUATEDPROBLEM_VIDEO_HPP
#define SITUATEDPROBLEM_VIDEO_HPP

#include <string>
#include "../Rating/Rating.hpp"

using namespace std;

class Video {
protected:
    string id;
    string name;
    int length;
    string genre;
    Rating rating;
public:
    Video(const string& id, const string& name, int length, const string& genre);
    virtual ~Video();
    virtual void show() const = 0;
    string getId() const;
    string getName() const;
    int getLength() const;
    string getGenre() const;
    virtual float getAverageRating() const;
    Video& operator+=(float r);
    virtual void validate() const;
};

#endif //SITUATEDPROBLEM_VIDEO_HPP
