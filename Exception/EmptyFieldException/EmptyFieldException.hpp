#ifndef SITUATEDPROBLEM_EMPTYFIELDEXCEPTION_HPP
#define SITUATEDPROBLEM_EMPTYFIELDEXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class EmptyFieldException : public exception {
private:
    string message;

public:
    EmptyFieldException(const string& fieldName);
    const char* what() const noexcept override;
};

#endif //SITUATEDPROBLEM_EMPTYFIELDEXCEPTION_HPP
