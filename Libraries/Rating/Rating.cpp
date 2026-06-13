#include "Rating.hpp"

Rating::Rating() {}

Rating& Rating::operator+=(float r) {
    if (r < 1.0f || r > 5.0f) {
        throw InvalidRatingException(r);
    }
    rates.push_back(r);
    return *this;
}

float Rating::getAverage() const {
    if (rates.empty()) {
        throw DivideByZeroException();
    }
    float sum = 0.0f;
    for (float r : rates) {
        sum += r;
    }
    return sum / rates.size();
}

bool Rating::isEmpty() const {
    return rates.empty();
}
