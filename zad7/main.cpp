#include "tabbit.hpp"
#include <climits>
using namespace obliczenia; 
using namespace std;

int main()
{
    // tabbit t(46); // tablica 46-bitowa (zainicjalizowana zerami)
    // tabbit u((uint64_t)45ULL); // tablica 64-bitowa (sizeof(uint64_t)*8)
    // tabbit v(t); // tablica 46-bitowa (skopiowana z t)
    // v[0] = 1; // ustawienie bitu 0-go bitu na 1
    // t[45] = true; // ustawienie bitu 45-go bitu na 1
    // bool b = v[1]; // odczytanie bitu 1-go
    // cout << b << "\n";
    // u[45] = u[46] = u[63]; // przepisanie bitu 63-go do 45-go i 46-go
    // cout << t << "\n"; // wyświetlenie zawartości tablicy bitów na ekranie

    tabbit a(10);
    cout << a << "\n";
    tabbit b(a);
    cout << b << "\n";

    a[7] = 1; a[1] = 1;
    cout << a << "\n";
    a[1] = false;
    cout << a << "\n";
    b[4] = b[3] = b[6] = 1;
    cout << b << "\n";
    a |= b;
    cout << a << "\n";
    cout << (a | b) << "\n";
    cout << a.rozmiar() << " " << b.rozmiar() << "\n";

    a = b;
    cout << a << "\n";

    tabbit c((uint64_t)ULONG_MAX);
    cout << c << "\n";

    c ^= a;
    b[9] = 1;
    b[8] = 1;
    cout << c << "\n";
    cout << (c & b) << "\n";

    tabbit e(1000);
    e[999] = e[998] = e[786] = e[777] = e[787] = e[0] = e[1] = e[76] = 1;
    cout << e << "\n";

    cout << a << "\n" << b << "\n";
    cout << (a & b) << "\n" << (a ^ b) << "\n" << (a | b) << "\n";
    b &= c;
    cout << c << "\n" << b << "\n";

    bool bb = e[998], cc = e[653];
    cout << bb << " " << cc << "\n";

    tabbit d(5);
    cin >> d;
    cout << d << "\n";
    cin >> a;
    cout << a << "\n";
}