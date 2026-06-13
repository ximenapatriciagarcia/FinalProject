#ifndef SITUATEDPROBLEM_INVALIDNUMBEREXCEPTION_HPP
#define SITUATEDPROBLEM_INVALIDNUMBEREXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class InvalidNumberException : public exception {
private:
    string message;

public:
    InvalidNumberException(const string& fieldName, int value);
    const char* what() const noexcept override;
};

#endif //SITUATEDPROBLEM_INVALIDNUMBEREXCEPTION_HPP
