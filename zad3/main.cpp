#include "kolejka.hpp"
#include <iostream>

int main()
{
    kolejka x(10);
    cout << "x:\n" << x.usun() << x.zprzodu() << x.dlugosc() << "\n";

    x.wstaw("jeden"); x.wstaw("dwa");
    cout << x.zprzodu() << " " << x.dlugosc() << "\n";
    cout << x.usun() << " " << x.zprzodu() << " " << x.dlugosc() << "\n";

    kolejka y = kolejka();
    y.wstaw("jeden");
    cout << "\ny:\n" << y.dlugosc() << " " << y.zprzodu() << "\n";
    y.wstaw("dwa");
    cout << y.dlugosc() << " " << y.zprzodu() << "\n";
    cout << y.usun() << " " << y.zprzodu() << " " << y.dlugosc() << "\n";

    kolejka z({"first","second","third","fourth"});
    cout << "\nz:\n" << z.dlugosc() << " " << z.zprzodu() << "\n";

    z.wstaw("jajco");
    cout << z.usun() << " " << z.usun() << " " << z.dlugosc() << "\n";
    while(z.dlugosc()) cout << z.usun() << " ";
    z.wstaw("new"); z.wstaw("zupa");
    cout << "\n" << z.dlugosc() << " " << z.usun() << " " << z.zprzodu() << " " << z.dlugosc() << "\n";

    kolejka q = z;
    cout << "\nq:\n" << q.dlugosc() << " " << q.usun() << " " << q.zprzodu() << " " << q.dlugosc() << "\n";
    cout << "z: " << z.dlugosc() << " " << z.zprzodu() << " " << z.dlugosc() << "\n"; // nie zmienilo z - skopiowal

    z.wstaw("maciek"); z.wstaw("jacek");
    cout << z.dlugosc() << " " << q.dlugosc() << "\n";
    q = z;
    cout << z.dlugosc() << " " << q.dlugosc() << "\n";

    while(q.dlugosc()) cout << q.usun() << " ";
    cout << "\n";
    while(z.dlugosc()) cout << z.usun() << " ";
    cout << "\n";

    z.wstaw("maciek"); z.wstaw("jacek");
    kolejka t = move(z);
    cout << "\nt:\n" << t.dlugosc() << " " << t.zprzodu() << "\n";
    cout << z.dlugosc() << " " << z.zprzodu() << "\n"; // z zostal usuniety  - przejęcie zawartosci

    q.wstaw("krowa"); q.wstaw("krowka"); q.wstaw("prosiak");
    cout << "q: " << q.dlugosc() << " " << q.zprzodu() << "\n";

    t = move(q);
    cout << "t: " << t.dlugosc() << " " << t.zprzodu() << "\n";
    cout << "q: " << q.dlugosc() << " " << q.zprzodu() << "\n"; // q stracil zawartosc (dziala (?))

    while(t.dlugosc()) cout << t.usun() << " ";
    cout << "\n";

    try {
        kolejka p(-1);
    } catch(exception &e) {
        cerr << e.what() << "\n";
    }
}