#include "macierz.hpp"
using namespace std;
using namespace obliczenia;

int main()
{
    // macierze
    macierz id {
        {1,0,0},
        {0,1,0},
        {0,0,1},
    };
    cout << id << "\n";

    macierz m(3,4);
    m[1] = {5,3,2,1};
    m[0][2] = m[2][1] = 7;
    macierz p(~m);
    macierz o(p);
    cout << m << "\n" << p << "\n" << o << "\n";
    cout << id*(m*p) << "\n" << 3*m << "\n" << p*5 << "\n";

    macierz q (3,4);
    q = m;
    cout << q + m << "\n" << m - q << "\n";
    m *= 3;
    q -= {
        {1,0,3,2},
        {0,0,1,1},
        {3,3,2,1}
    };
    cout << q << "\n" << m << "\n";
    m = q*2;
    cout << m << "\n" << -m << "\n";

    // macierz s(3,2);
    // cin >> s;
    // cout << "\n" << 2*s << "\n";

    //wektory
    wektor v(4);
    v[1] = v[2] = 2;
    cout << v << "\n";
    wektor w(v);
    w += {1,3,4,1};
    cout << w << "\n" << w - v << "\n" << w + v << "\n";

    wektor u {3,-1,5,-3,9,2};
    cout << 2*u << "\n" << u*(-2) << "\n" << -u << "\n";

    u *= 3;
    u += {1,1,1,1,1,1};
    cout << u << "\n";
    
    u -= {1,2,3,4,5,6};
    cout << u << "\n";

    // cin >> u;
    cout << u.get_size() << "\n" << -u << "\n";
}