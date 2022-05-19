#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include "rational_exception.hpp"

namespace obliczenia {
    class rational {
        int num, denom;

    public:
        rational(int _num, int _denom = 1);

        friend rational operator + (const rational &a, const rational &b);
        friend rational operator - (const rational &a, const rational &b);
        friend rational operator * (const rational &a, const rational &b);
        friend rational operator / (const rational &a, const rational &b);

        friend rational operator - (const rational &a);
        friend rational operator ! (const rational &a); // 1/x

        rational & operator += (const rational &a);
        rational & operator -= (const rational &a);
        rational & operator *= (const rational &a);
        rational & operator /= (const rational &a);

        operator double ();
        operator double () const;
        operator int ();
        operator int () const;

        friend std::istream & operator >> (std::istream &is, rational &a);
        friend std::ostream & operator << (std::ostream &os, const rational &a);
    };

    // friend operators
    rational operator + (const rational &a, const rational &b);
    rational operator - (const rational &a, const rational &b);
    rational operator * (const rational &a, const rational &b);
    rational operator / (const rational &a, const rational &b);

    rational operator - (const rational &a);
    rational operator ! (const rational &a);

    std::istream & operator >> (std::istream &is, rational &a);
    std::ostream & operator << (std::ostream &os, const rational &a);
};

#endif