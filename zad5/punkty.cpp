#include "punkty.hpp"
#include <cmath>
#include <stdexcept>

#define __eps 1e-10

//punkt
punkt::punkt() : punkt(0,0) {}
punkt::punkt(double _x, double _y) : x(_x), y(_y) {}

double punkt::get_x() {return x;}
double punkt::get_y() {return y;}
void punkt::set_x(double v) {x = v;}
void punkt::set_y(double v) {y = v;}

double punkt::odleglosc(punkt a)
{
    return sqrt((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y));
}
bool punkt::wspolliniowe(punkt a, punkt b, punkt c)
{
    if(abs(a.x-b.x) < __eps) return abs(c.x-a.x) < __eps;
    return abs((a.y-b.y)/(a.x-b.x)-(a.y-c.y)/(a.x-c.x)) < __eps;
}

//punkt nazwany
bool check_nazwa(std::string nazwa)
{
    if(nazwa == "") return true;
    if(!(('a' <= nazwa[0] && nazwa[0] <= 'z') || ('A' <= nazwa[0] && nazwa[0] <= 'Z')))
        return false;
    for(auto i : nazwa)
        if(!(('0' <= i && i <= '9') || ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z')))
            return false;
    return true;
}

punkt_nazwany::punkt_nazwany() : punkt_nazwany("") {}
punkt_nazwany::punkt_nazwany(std::string _nazwa) : punkt_nazwany(0,0,_nazwa) {}
punkt_nazwany::punkt_nazwany(double _x, double _y, std::string _nazwa) : punkt(_x,_y), nazwa(_nazwa) 
{
    if(!check_nazwa(nazwa)) throw std::invalid_argument("Nieprawidlowa nazwa punktu");
}

std::string punkt_nazwany::get_nazwa() {return nazwa;}
void punkt_nazwany::set_nazwa(const std::string &s)
{
    if(!check_nazwa(s)) throw std::invalid_argument("Nieprawidlowa nazwa punktu");
    nazwa = s;
}

//punkt kolorowy
punkt_kolorowy::punkt_kolorowy(kolor_transparentny _kol) : punkt_kolorowy(0,0,_kol) {}
punkt_kolorowy::punkt_kolorowy(double _x, double _y, kolor_transparentny _kol) : punkt(_x,_y), kol(_kol) {}

kolor_transparentny punkt_kolorowy::get_kolor() {return kol;}
void punkt_kolorowy::set_kolor(const kolor_transparentny &_kol) {kol = _kol;}

//punkt kolorowy nazwany
punkt_kolorowy_nazwany::punkt_kolorowy_nazwany(std::string _nazwa, kolor_transparentny _kol) : 
    punkt_kolorowy_nazwany(0,0,_nazwa,_kol) {}
punkt_kolorowy_nazwany::punkt_kolorowy_nazwany(double _x, double _y, std::string _nazwa, kolor_transparentny _kol) : 
    punkt(_x,_y), punkt_kolorowy(_kol), punkt_nazwany(_nazwa) {}

//wektory
wektor2d::wektor2d(double _x, double _y) : x(_x), y(_y) {}
wektor3d::wektor3d(double _x, double _y, double _z) : wektor2d(_x,_y), z(_z) {}

punkt2d::punkt2d(double _x, double _y) : punkt(_x,_y) {}
void punkt2d::transpozycja(wektor2d v) 
{
    x += v.x;
    y += v.y;
}

punkt3d::punkt3d(double _x, double _y, double _z) : punkt2d(_x,_y), z(_z) {}

double punkt3d::get_z() {return z;}
void punkt3d::set_z(double _z) {z = _z;}

void punkt3d::transpozycja(wektor3d v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}
double punkt3d::odleglosc(punkt3d a)
{
    return sqrt((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y) + (z-a.z)*(z-a.z));
}
bool punkt3d::wspolliniowe(punkt3d a, punkt3d b, punkt3d c)
{
    wektor3d ab(b.x-a.x, b.y-a.y, b.z-a.z);
    wektor3d ac(c.x-a.x, c.y-a.y, c.z-a.z);

    return (abs(ab.y*ac.z - ab.z*ac.y) < __eps) && 
           (abs(ab.x*ac.z - ab.z*ac.x) < __eps) && 
           (abs(ab.x*ac.y - ab.y*ac.x) < __eps);
    // wspolliniowe jesli wektory ab i ac sa rownolegle <=> iloczyn wektorowy = 0
}