#include "Movie.hpp"
#include <iostream>

Movie::Movie(const string& id, const string& name, int length, const string& genre) : Video(id, name, length, genre) {}

void Movie::show() const {
    cout << "[Movie] " << this->name  << " | Genre: " << this->genre
         << " | Length: " << this->length << " min" << " | Rating: " << getAverageRating() << endl;
}