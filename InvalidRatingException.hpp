#ifndef SITUATEDPROBLEM_INVALIDRATINGEXCEPTION_HPP
#define SITUATEDPROBLEM_INVALIDRATINGEXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class InvalidRatingException : public exception {
private:
    string message;

public:
    InvalidRatingException(float rating);
    const char* what() const noexcept override;
};

#endif //SITUATEDPROBLEM_INVALIDRATINGEXCEPTION_HPP