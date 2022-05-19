#include "rational.hpp"
#include <climits>
#include <cmath>

using namespace obliczenia;

long long hcf(long long a, long long b) { return b == 0 ? a : hcf(b,a%b); }
int sgn(int a) { return a < 0 ? -1 : 1; }

rational::rational(int _num, int _denom) 
{
    if(_denom == 0) throw zero_division_exception("Mianownik musi byc niezerowy!");

    int s = sgn(_num) * sgn(_denom); // znak
    int d = hcf(abs(_num),abs(_denom));

    num = s * abs(_num) / d;
    denom = abs(_denom) / d;
}

rational obliczenia::operator + (const rational &a, const rational &b)
{
    long long d = (long long)a.denom * (long long)b.denom;
    long long n = (long long)a.num*b.denom + (long long)b.num*a.denom;

    long long h = hcf(abs(n),d);
    d /= h;
    n /= h;

    if(INT_MAX < d || n < INT_MIN || INT_MAX < n) throw overflow_exception("+: przekroczenie zakresu");

    return rational(n,d);
}
rational obliczenia::operator - (const rational &a, const rational &b)
{
    return a + (-b);
}
rational obliczenia::operator * (const rational &a, const rational &b)
{
    long long d = (long long)a.denom * (long long)b.denom;
    long long n = (long long)a.num * (long long)b.num;

    long long h = hcf(abs(n),d);
    d /= h;
    n /= h;

    if(INT_MAX < d || n < INT_MIN || INT_MAX < n) throw overflow_exception("*: przekroczenie zakresu");

    return rational(n,d);
}
rational obliczenia::operator / (const rational &a, const rational &b)
{
    if(b.num == 0) throw zero_division_exception("Dzielenie przez zero jest nielegalne");
    return a * !b; // a / b == a * 1/b
}

rational obliczenia::operator - (const rational &a) { return rational(-a.num, a.denom); }
rational obliczenia::operator ! (const rational &a) { return rational( a.denom, a.num); }

rational & rational::operator += (const rational &a)
{
    return *this = *this + a;
}
rational & rational::operator -= (const rational &a)
{
    return *this = *this - a;
}
rational & rational::operator *= (const rational &a)
{
    return *this = *this * a;
}
rational & rational::operator /= (const rational &a)
{
    return *this = *this / a;
}

rational::operator double ()
{
    return (double)num/denom;
}
rational::operator double () const
{
    return (double)num/denom;
}
rational::operator int ()
{
    return round((double)(*this));
}
rational::operator int () const
{
    return round((double)(*this));
}

std::istream & obliczenia::operator >> (std::istream &is, rational &a)
{
    int n, d;
    is >> n >> d;
    a = rational(n,d);
    return is;
}
std::ostream & obliczenia::operator << (std::ostream &os, const rational &a)
{
    uint64_t p = abs(a.num), q = a.denom;

    if(q % 5 == 0 || q % 2 == 0 || p % q == 0) return os << (double)a << "\n";

    std::string str = (a.num < 0 ? "-" : "") + std::to_string(p/q);
    p = p%q;

    uint64_t x, n = 9;

    for(uint64_t i = 1; i < 10; i++)
    {
        x = (p*n)/q;
        if((p*n) % q == 0) break;
        n = n*10 + 9;
    }

    return os << str + ".(" << std::to_string(x) << ")\n";
}