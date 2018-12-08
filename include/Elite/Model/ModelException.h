#ifndef MODEL_EXCEPTION_H
#define MODEL_EXCEPTION_H

#include <exception>
#include <string>
namespace Elite {

class FunctionNotImplement : public std::exception {
public:
    FunctionNotImplement(const char* func_name, const char* msg) : std::exception() {
        this->func_name = func_name;
        this->msg += msg;
        this->msg += " (";
        this->msg += func_name;
        this->msg += ")\n";
    }
    virtual const char* what() const noexcept {
        return msg.c_str();
    }
    std::string msg;
    const char* func_name;
};

}

#endif