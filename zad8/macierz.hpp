#ifndef MACIERZ_HPP
#define MACIERZ_HPP

#include <iostream>
#include "wyjatki.hpp"

namespace obliczenia {
    class wektor {
        double *tab = nullptr;
        const int size;
    public:
        wektor(int _size);
        wektor(std::initializer_list<double> l);
        wektor(const wektor &x);    // konstruktor kopiujący
        wektor(wektor &&x);         // konstruktor przenoszący

        ~wektor();

        wektor & operator = (const wektor &x);  // przypisanie kopiujące
        wektor & operator = (wektor &&x);       // przypisanie przenoszące

        double operator [] (int i) const;
        double & operator [] (int i);

        friend std::istream & operator >> (std::istream &is, wektor &w);
        friend std::ostream & operator << (std::ostream &os, const wektor &w);

        friend wektor operator-(const wektor &v);                   // zmiana znaku
        friend wektor operator+(const wektor &x, const wektor &y);
        friend wektor operator-(const wektor &x, const wektor &y);
        friend wektor operator*(const wektor &v, double d);         // mnozenie przez stala
        friend wektor operator*(double d, const wektor &v);         // mnozenie przez stala
        friend double operator*(const wektor &x, const wektor &y);  // iloczyn skalarny x*y

        wektor & operator+=(const wektor &v);
        wektor & operator-=(const wektor &v);
        wektor & operator*=(double d);

        int get_size() const;
    };

    class macierz {
        wektor **tab = nullptr;
        const int rows, cols;
    public:
        macierz(int _rows, int _cols);
        macierz(std::initializer_list<wektor> l);
        macierz(const macierz &x);  // konstruktor kopiujący
        macierz(macierz &&x);       // konsturktor przenoszący

        ~macierz();

        macierz & operator = (const macierz &x);    // przypisanie kopiujące
        macierz & operator = (macierz &&x);         // przypisanie przenoszące

        wektor & operator [] (int i) const;
        wektor & operator [] (int i);

        friend std::istream & operator >> (std::istream &is, macierz &m);
        friend std::ostream & operator << (std::ostream &os, const macierz &m);

        friend macierz operator-(const macierz &m); // zmiana znaku
        friend macierz operator+(const macierz &p, const macierz &q);
        friend macierz operator-(const macierz &p, const macierz &q);
        friend macierz operator*(const macierz &m, double d);
        friend macierz operator*(double d, const macierz &m);
        friend macierz operator*(const macierz &p, const macierz &q);
        friend macierz operator~(const macierz &m); // transpozycja

        macierz & operator+=(const macierz &m);
        macierz & operator-=(const macierz &m);
        macierz & operator*=(double d);
    };

     // zaprzyjaznione operatory - wektor
    std::istream & operator >> (std::istream &is, wektor &w);
    std::ostream & operator << (std::ostream &os, const wektor &w);

    wektor operator-(const wektor &v);                   // zmiana znaku
    wektor operator+(const wektor &x, const wektor &y);
    wektor operator-(const wektor &x, const wektor &y);
    wektor operator*(const wektor &v, double d);         // mnozenie przez stala
    wektor operator*(double d, const wektor &v);         // mnozenie przez stala
    double operator*(const wektor &x, const wektor &y);  // iloczyn skalarny x*y

    // zaprzyjaznione operatory - macierz
    std::istream & operator >> (std::istream &is, macierz &m);
    std::ostream & operator << (std::ostream &os, const macierz &m);

    macierz operator-(const macierz &m); // zmiana znaku
    macierz operator+(const macierz &p, const macierz &q);
    macierz operator-(const macierz &p, const macierz &q);
    macierz operator*(const macierz &m, double d);
    macierz operator*(double d, const macierz &m);
    macierz operator*(const macierz &p, const macierz &q);
    macierz operator~(const macierz &m); // transpozycja
};

#endif 