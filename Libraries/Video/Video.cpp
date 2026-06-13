#include "Video.hpp"
#include "../../Exception/InvalidRatingException/InvalidRatingException.hpp"
#include "../../Exception/EmptyFieldException/EmptyFieldException.hpp"
#include "../../Exception/InvalidNumberException/InvalidNumberException.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"
#include <iostream>

using namespace std;

Video::Video(const string &id, const string &name, int length, const string &genre) : id(id), name(name),
length(length), genre(genre) {}

Video::~Video() {};

string Video::getId() const {
    return id;
}

string Video::getName() const {
    return name;
}

int Video::getLength() const {
    return length;
}

string Video::getGenre() const {
    return genre;
}

float Video::getAverageRating() const {
    if (this->ratings.empty()) {
        throw DivideByZeroException();
    }

    float sum = 0.0;

    for (float r : this->ratings) {
        sum += r;
    }
    return sum / this->ratings.size();
}

Video& Video::operator+=(float rating) {
    if (rating < 1.0 || rating > 5.0) {
        throw InvalidRatingException(rating);
    }
    this->ratings.push_back(rating);
    return *this;
}

void Video::validate() const {
    if (this->id.empty()) {
        throw EmptyFieldException("id");
    }
    if (this->name.empty()) {
        throw EmptyFieldException("name");
    }
    if (this->genre.empty()) {
        throw EmptyFieldException("genre");
    }
    if (this->length <= 0) {
        throw InvalidNumberException("length", this->length);
    }
}
