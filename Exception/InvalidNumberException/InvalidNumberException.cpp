#include "InvalidNumberException.hpp"
using namespace std;

InvalidNumberException::InvalidNumberException(const string& fieldName, int value) {
    this->message = "Invalid value for '" + fieldName + "': " + to_string(value)
                    + ". Must be greater than 0.";
}

const char* InvalidNumberException::what() const noexcept {
    return message.c_str();
}
