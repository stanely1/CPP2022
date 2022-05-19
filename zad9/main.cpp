#include "rational.hpp"
#include <climits>

using namespace std;
using namespace obliczenia;

int main()
{
    rational x(-17,6);
    cout << x;

    rational a(-9,-27);
    rational b(10,-12);
    cout << a << b << (a+b) << (a-b) << (a*b) << (a/b);
    a /= b;
    a += rational(3,6);
    a -= rational(4,18);
    a *= rational(-9,15);
    cout << a << !a << -a;

    cout << b << (int)b << " " << (double)b << "\n";

    rational c = rational(18);
    cout << c;

    try {
        rational d = rational(91,0);
        d += c;
    } catch(zero_division_exception &e) {
        cout << e.what() << "\n";
    }
    
    b = rational(0,1001);
    cout << b;
    try {
        a /= b;
    } catch (zero_division_exception &e) {
        cout << e.what() << "\n";
    }

    a = rational(INT_MAX-1);
    b = rational(1,INT_MIN+1);
    cout << a << b;
    try {
        cout << a - b;
    } catch(overflow_exception &e) {
        cout << e.what() << "\n";
    }
    try {
        cout << a / b;
    } catch(overflow_exception &e) {
        cout << e.what() << "\n";
    }
    cout << b * a;

    cin >> c;
    cout << c;
}