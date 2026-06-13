#include "Video.hpp"
#include "../../Exception/EmptyFieldException/EmptyFieldException.hpp"
#include "../../Exception/InvalidNumberException/InvalidNumberException.hpp"
#include <iostream>

using namespace std;

Video::Video(const string& id, const string& name, int length, const string& genre)
    : id(id), name(name), length(length), genre(genre) {}

Video::~Video() {}

string Video::getId() const { return id; }
string Video::getName() const { return name; }
int Video::getLength() const { return length; }
string Video::getGenre() const { return genre; }

float Video::getAverageRating() const {
    return rating.getAverage();
}

Video& Video::operator+=(float r) {
    rating += r;
    return *this;
}

void Video::validate() const {
    if (id.empty()) throw EmptyFieldException("id");
    if (name.empty()) throw EmptyFieldException("name");
    if (genre.empty()) throw EmptyFieldException("genre");
    if (length <= 0) throw InvalidNumberException("length", length);
}
