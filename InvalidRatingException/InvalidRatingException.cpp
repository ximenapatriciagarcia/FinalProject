#include "InvalidRatingException.hpp"
using namespace std;

InvalidRatingException::InvalidRatingException(float rating) {
    this->message = "Invalid rating: " + to_string(rating) + ". Must be between 1 and 5.";
}

const char* InvalidRatingException::what() const noexcept {
    return message.c_str();
}
