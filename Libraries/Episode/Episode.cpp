#include "Episode.hpp"
#include "../../Exception/EmptyFieldException/EmptyFieldException.hpp"
#include "../../Exception/InvalidNumberException/InvalidNumberException.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"
#include <iostream>

using namespace std;

Episode::Episode(const string& t, int s) : title(t), season(s) {}

Episode::~Episode(){}

string Episode::getTitle() const {
    return title;
}

int Episode::getSeason() const {
    return season;
}

float Episode::getAverageRating() const {
    if (this->ratings.empty()) {
        throw DivideByZeroException();
    }

    float sum = 0.0;

    for (float r : this->ratings) {
        sum += r;
    }
    return sum / this->ratings.size();
}

Episode& Episode::operator+=(float rating) {
    if (rating < 1.0 || rating > 5.0) {
        throw InvalidRatingException(rating);
    }
    this->ratings.push_back(rating);
        return *this;
}

void Episode::show() const {
    cout << "Episode: " << this->title
    << " | Season: " << this->season
    << " | Rating: ";
    try {
        cout << getAverageRating();
    } catch (DivideByZeroException& e) {
        cout << "Not rated";
    }
    cout << endl;
}

void Episode::validate() const {
    if (this->title.empty()) {
        throw EmptyFieldException("title");
    }
    if (this->season <= 0) {
        throw InvalidNumberException("season", this->season);
    }
}