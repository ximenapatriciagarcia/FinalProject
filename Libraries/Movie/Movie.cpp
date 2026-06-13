#include "Movie.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"
#include <iostream>

Movie::Movie(const string& id, const string& name, int length, const string& genre) : Video(id, name, length, genre) {}

void Movie::show() const {
    cout << "[Movie] " << this->name  << " | Genre: " << this->genre
         << " | Length: " << this->length << " min" << " | Rating: ";
    try {
        cout << getAverageRating();
    } catch (DivideByZeroException& e) {
        cout << "Not rated";
    }
    cout << endl;
}