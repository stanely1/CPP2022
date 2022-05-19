#include "rational_exception.hpp"

rational_exception::rational_exception(const char *what) : logic_error(what) {}
zero_division_exception::zero_division_exception(const char *what) : rational_exception(what) {}
overflow_exception::overflow_exception(const char *what) : rational_exception(what) {}