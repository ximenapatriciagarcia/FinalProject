#ifndef SITUATEDPROBLEM_EPISODE_HPP
#define SITUATEDPROBLEM_EPISODE_HPP

#include "../Video/Video.hpp"

class Episode : public Video {
public:
    Episode(const string& id, const string& title, int length, const string& genre);
    void show() const override;
};

#endif //SITUATEDPROBLEM_EPISODE_HPP
