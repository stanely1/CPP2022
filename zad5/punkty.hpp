#ifndef PUNKTY_HPP
#define PUNKTY_HPP

#include "kolory.hpp"

class punkt {
protected:
    double x, y;
public:
    punkt();
    punkt(double _x, double _y);

    double get_x();
    double get_y();
    void set_x(double v);
    void set_y(double v);

    double odleglosc(punkt a);
    static bool wspolliniowe(punkt a, punkt b, punkt c);
};

class punkt_nazwany : public virtual punkt {
protected:
    std::string nazwa;
public:
    punkt_nazwany();
    punkt_nazwany(std::string _nazwa);
    punkt_nazwany(double _x, double _y, std::string _nazwa);

    std::string get_nazwa();
    void set_nazwa(const std::string &s);
};

class punkt_kolorowy : public virtual punkt {
protected:
    kolor_transparentny kol;
public:
    punkt_kolorowy(kolor_transparentny _kol = kolor_transparentny());
    punkt_kolorowy(double _x, double _y, kolor_transparentny _kol);

    kolor_transparentny get_kolor();
    void set_kolor(const kolor_transparentny &_kol);
};

class punkt_kolorowy_nazwany : public punkt_kolorowy, public punkt_nazwany {
public:
    punkt_kolorowy_nazwany(std::string _nazwa = "", kolor_transparentny _kol = kolor_transparentny());
    punkt_kolorowy_nazwany(double _x, double _y, std::string _nazwa, kolor_transparentny _kol);
};

class wektor2d {
public:
    double x, y; 
    wektor2d(double _x, double _y);
};
class wektor3d : public wektor2d {
public:
    double z;
    wektor3d(double _x, double _y, double _z);
};

class punkt2d : public punkt {
public:
    punkt2d(double _x, double _y);
    void transpozycja(wektor2d v);
};

class punkt3d: public punkt2d {
protected: 
    double z;
public:
    punkt3d(double _x, double _y, double _z);

    double get_z();
    void set_z(double _z);

    void transpozycja(wektor3d v);
    double odleglosc(punkt3d a);
    static bool wspolliniowe(punkt3d a, punkt3d b, punkt3d c);
};

#endif