#include "DivideByZeroException.hpp"
using namespace std;

DivideByZeroException::DivideByZeroException() {
    this->message = "Attempted to divide by zero (no ratings available to average).";
}

const char* DivideByZeroException::what() const noexcept {
    return message.c_str();
}
