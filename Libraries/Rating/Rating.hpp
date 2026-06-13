#ifndef RATING_H
#define RATING_H

#include <vector>
#include "../../Exception/InvalidRatingException/InvalidRatingException.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"

class Rating {
private:
    std::vector<float> rates;
public:
    Rating();
    Rating& operator+=(float r);
    float getAverage() const;
    bool isEmpty() const;
};

#endif
