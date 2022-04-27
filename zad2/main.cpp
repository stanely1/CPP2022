#include <iostream>
#include "zmienne.hpp"

int main()
{
    zmienna x;
    zmienna y("igrek");
    zmienna z("zet", 5);

    cout << x.get_name() << " " << x.get_val() << "\n";
    cout << y.get_name() << " " << y.get_val() << "\n";
    cout << z.get_name() << " " << z.get_val() << "\n";

    zbior_zmiennych secior(10); // (2); //przepelnienie tablicy

    try {
        zbior_zmiennych secior2(-3); //zly rozmiar tablicy
    } catch(std::invalid_argument &e) {cerr << e.what() << "\n";}

    secior.wypisz();

    secior.wstaw(x); 
    secior.wstaw(y);
    secior.wstaw(z);

    try {
        secior.wstaw(z); // wstawienie drugi raz tej samej zmiennej
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    secior.wypisz();

    cout << secior.znajdz("mariusz") << " " << secior.znajdz("igrek") << " " << secior.znajdz(x.get_name()) << "\n";
    cout << secior.get_val("zet") << "\n";

    try {
        cout << secior.get_val("aaa") << "\n"; // proba odczytu zmiennej ktorej nie ma w zbiorze
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    cout << secior.get_val("igrek") << "\n";
    secior.set_val("igrek",6.9);

    try {
        secior.set_val("malpa",6.9); // proba ustawienia zmiennej ktorej nie ma w zbiorze
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    cout << secior.get_val("igrek") << "\n";

    secior.wypisz();
    secior.usun("_");
    secior.wypisz();

    secior.wstaw(zmienna("maciek",4));
    secior.wstaw(zmienna("jacek",4.20));
    secior.wypisz();

    secior.usun("zet");

    try {
        secior.usun("michal"); //proba usuniecia zmiennej ktorej nie ma w zbiorze
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    secior.wypisz();

    secior.wstaw(zmienna());
    secior.wstaw(zmienna("babcia"));
    secior.wypisz();

    secior.set_val("babcia",-8931);
    secior.set_val("_",-21.37);
    secior.wypisz();

    try {
        secior.wstaw(zmienna("0/9,..c,^^^"));
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    try {
        secior.wstaw(zmienna("9_bCD__09_AcB"));
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    try {
        secior.wstaw(zmienna(""));
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    try {
        secior.wstaw(zmienna("_aA09,"));
    } catch(invalid_argument &e) {cerr << e.what() << "\n";}

    secior.wstaw(zmienna("_aA01"));
    secior.set_val("_aA01", -0.901);
    secior.wypisz();

    zbior_zmiennych secior2(1);

    secior2.wstaw(zmienna("jajo",90));
    try {
        secior2.wstaw(zmienna("jajeczko",420.69));
    } catch(length_error &e) {cerr << e.what() << "\n";}

    secior2.wypisz();
}