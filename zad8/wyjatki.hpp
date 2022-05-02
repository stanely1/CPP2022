#ifndef WYJATKI_HPP
#define WYJATKI_HPP

#include <stdexcept>

class invalid_size : public std::logic_error {
public:
    invalid_size(const char *what);
};

class invalid_vector_size : public invalid_size {
public:
    invalid_vector_size(const char *what);
};

class invalid_matrix_size : public invalid_size {
public:
    invalid_matrix_size(const char *what);
};

#endif