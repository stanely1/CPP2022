#ifndef WIELOMIAN_HPP
#define WIELOMIAN_HPP

#include <initializer_list>
#include <iostream>

class wielomian {
    int n;
    double *a;

public: 
    wielomian (int st = 0, double wsp = 1.0); // konstruktor jednomianu
    wielomian (int st, const double wsp[]); // konstruktor wielomianu
    wielomian (std::initializer_list<double> wsp); // lista współczynników
    wielomian (const wielomian &w); // konstruktor kopiujący
    wielomian (wielomian &&w); // konstruktor przenoszący

    wielomian& operator = (const wielomian &w); // przypisanie kopiujące
    wielomian& operator = (wielomian &&w); // przypisanie przenoszące

    ~wielomian (); // destruktor

    friend std::istream& operator >> (std::istream &we, wielomian &w);
    friend std::ostream& operator << (std::ostream &wy, const wielomian &w);

    friend wielomian operator + (const wielomian &u, const wielomian &v);
    friend wielomian operator - (const wielomian &u, const wielomian &v);
    friend wielomian operator * (const wielomian &u, const wielomian &v);

    friend wielomian operator * (const wielomian &u, double c);
    wielomian& operator += (const wielomian &v);
    wielomian& operator -= (const wielomian &v);
    wielomian& operator *= (const wielomian &v);
    wielomian& operator *= (double c);
    double operator () (double x) const; // wartość wielomianu dla x
    double operator [] (int i) const; // do odczytu współczynnika
    double& operator [] (int i); // do zapisu współczynnika

    int get_deg();
};

#endif 