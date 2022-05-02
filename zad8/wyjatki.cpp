#include "wyjatki.hpp"

invalid_size::invalid_size(const char *what) : std::logic_error(what) {}
invalid_vector_size::invalid_vector_size(const char *what) : invalid_size(what) {}
invalid_matrix_size::invalid_matrix_size(const char *what) : invalid_size(what) {}