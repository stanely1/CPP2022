#ifndef RATIONAL_EXCEPTION_HPP
#define RATIONAL_EXCEPTION_HPP

#include <stdexcept>

class rational_exception : public std::logic_error {
public:
    rational_exception(const char *what);
};

class zero_division_exception : public rational_exception {
public:
    zero_division_exception(const char *what);
};

class overflow_exception : public rational_exception {
public:
    overflow_exception(const char *what);
};

#endif