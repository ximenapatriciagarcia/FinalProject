#ifndef SITUATEDPROBLEM_MOVIE_HPP
#define SITUATEDPROBLEM_MOVIE_HPP

#include "../Video/Video.hpp"

using namespace std;

class Movie : public Video {
public:
    Movie(const string& id, const string& name, int length, const string& genre);
    void show() const override;
};

#endif //SITUATEDPROBLEM_MOVIE_HPP