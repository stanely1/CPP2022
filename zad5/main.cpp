#include "kolory.hpp"
#include "punkty.hpp"
#include <iostream>
using namespace std;

int main()
{
    // kolory
    cout << "kolory:\n";
    kolor k(12,34,123);
    kolor_transparentny kt(9,89,123,100);
    kolor_nazwany kn(1,23,45,65,"mariusz");

    cout << k.get_r() << " " << kt.get_b() << " " << kt.get_a()  << " " 
    << kn.get_g() << " " << kn.get_a() << " " << kn.get_nazwa() << "\n";

    k.set_r(69), kt.set_a(98); kn.set_nazwa("waldek");
    cout << k.get_r() << " " << kt.get_a() << " " << kn.get_nazwa() << "\n";

    k = kolor::sum(k, kt);
    cout << k.get_r() << " " << k.get_g() << " " << k.get_b() << "\n\n";

    //punkty
    cout << "punkty:\n";
    punkt p(1.9,3.5); punkt_nazwany pn(1,2,"Marcin"); punkt_kolorowy pk(3.14,5,kt);
    cout << p.get_x() << " " << pn.get_y() << " " << pn.get_nazwa() 
         << " " << pk.get_x() << " " << pk.get_kolor().get_a() << "\n";

    p.set_x(420), pn.set_nazwa("Janek"), pn.set_y(9), pk.set_x(90);
    cout << p.get_x() << " " << pn.get_y() << " " << pn.get_nazwa() 
         << " " << pk.get_x() << " " << pk.get_kolor().get_r() << "\n";

    punkt_kolorowy_nazwany pkn(34,69,"Janusz",kt);
    cout << pkn.get_x() << " " << pkn.get_y() << " " << pkn.get_kolor().get_r() 
         << " " << pkn.get_nazwa() << "\n";

    pkn.set_kolor(kolor_transparentny(10,20,30,40));
    pkn.set_nazwa("Kajtek"); pkn.set_x(89), pkn.set_y(77.76);
    cout << pkn.get_x() << " " << pkn.get_y() << " " << pkn.get_kolor().get_r() 
         << " " << pkn.get_nazwa() << "\n";

    cout << pkn.odleglosc(pk) << " " << p.odleglosc(pn) << " " << punkt::wspolliniowe(p,pk,pkn) << "\n";
    p.set_x(3), p.set_y(16);
    pk.set_x(0.5), pk.set_y(8.5);
    pkn.set_x(-2), pkn.set_y(1);
    cout << punkt::wspolliniowe(p,pk,pkn) << "\n";

    punkt2d p2(8,9);
    punkt3d p3(1,2,3);
    punkt3d a(4,4,6);
    cout << p3.get_z() << " " << p3.punkt2d::odleglosc(p2) << " " << p3.odleglosc(a) << "\n";
    p3.set_z(5);
    cout << p3.get_z() << " " << p3.punkt2d::odleglosc(p2) << " " << p3.odleglosc(a) << "\n";

    wektor2d v2(-3,6);
    wektor3d v3(8,-4,2);
    p2.transpozycja(v2);
    p3.transpozycja(v3);
    cout << p2.get_x() << " " << p2.get_y() << " " << p3.get_x() << " " << p3.get_y() << " " << p3.get_z() << "\n";

    punkt3d b(19,-14,9);
    cout << punkt3d::wspolliniowe(a,p3,b) << " ";
    b.transpozycja(wektor3d(0,-1,0));
    cout << punkt3d::wspolliniowe(a,p3,b) << "\n";
}