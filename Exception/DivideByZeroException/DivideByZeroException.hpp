#ifndef SITUATEDPROBLEM_DIVIDEBYZEROEXCEPTION_HPP
#define SITUATEDPROBLEM_DIVIDEBYZEROEXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class DivideByZeroException : public exception {
private:
    string message;

public:
    DivideByZeroException();
    const char* what() const noexcept override;
};

#endif //SITUATEDPROBLEM_DIVIDEBYZEROEXCEPTION_HPP
