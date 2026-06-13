#include "EmptyFieldException.hpp"
using namespace std;

EmptyFieldException::EmptyFieldException(const string& fieldName) {
    this->message = "Empty field: '" + fieldName + "' cannot be empty.";
}

const char* EmptyFieldException::what() const noexcept {
    return message.c_str();
}
