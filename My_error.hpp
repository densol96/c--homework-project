#ifndef MY_ERROR_HPP
#define MY_ERROR_HPP

#include <exception>
#include <string>

using namespace std;

class My_error : public exception
{
private:
    string error_message;

public:
    My_error() = delete;
    My_error(const string &error_message) noexcept;
    virtual ~My_error() = default;

    virtual const char *what() const noexcept override;
};

#endif