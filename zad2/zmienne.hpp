#ifndef ZMIENNE_H
#define ZMIENNE_H

#include <string>
using namespace std;

class zmienna {
    string nazwa;
    double wartosc;
    bool name_valid();

public:
    zmienna();
    zmienna(string _nazwa);
    zmienna(string _nazwa, double _wartosc);

    string get_name();
    double get_val();
    void set_val(double _wartosc);
};

class zbior_zmiennych {
    const int n;
    int current_ind; // indeks za ostatnim elementem - pierwsze wolne miejsce
    zmienna *tab;

public:
    zbior_zmiennych(const int _n);
    ~zbior_zmiennych();

    void wstaw(zmienna x);
    bool znajdz(string nazwa);
    void usun(string nazwa);
    double get_val(string nazwa);
    void set_val(string nazwa, double wartosc);

    void wypisz();
};

#endif