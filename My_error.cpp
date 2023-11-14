#include "My_error.hpp"

My_error::My_error(const string &error_message) noexcept
    : error_message{error_message} {}

const char *My_error::what() const noexcept
{
    return error_message.c_str();
}
