#include "kolory.hpp"
#include <stdexcept>

bool invalid_color(int v)
{
    return v < 0 || 255 < v;
}
// kolor
kolor::kolor() : kolor(0,0,0) {}
kolor::kolor(int _r, int _g, int _b) : r(_r), g(_g), b(_b)
{
    if(invalid_color(r) || invalid_color(g) || invalid_color(b))
        throw std::invalid_argument("Nieprawidlowa wartosc koloru");
}

int kolor::get_r() {return r;}
int kolor::get_g() {return g;}
int kolor::get_b() {return b;}
void kolor::set_r(int v) 
{
    if(invalid_color(v)) throw std::invalid_argument("Nieprawdlowa wartosc koloru");
    r = v;
}
void kolor::set_g(int v) 
{
    if(invalid_color(v)) throw std::invalid_argument("Nieprawdlowa wartosc koloru");    
    g = v;
}
void kolor::set_b(int v) 
{
    if(invalid_color(v)) throw std::invalid_argument("Nieprawdlowa wartosc koloru");
    b = v;
}

kolor kolor::sum(kolor a, kolor b)
{
    return kolor((a.get_r()+b.get_r())/2, (a.get_g()+b.get_g())/2, (a.get_b()+b.get_b())/2);
}

//kolor transparentny
kolor_transparentny::kolor_transparentny() : kolor(), a(0) {}
kolor_transparentny::kolor_transparentny(int _r, int _g, int _b, int _a) : kolor(_r,_g,_b), a(_a)
{
    if(invalid_color(a)) throw std::invalid_argument("Nieprawidlowa wartosc alfa");
}

int kolor_transparentny::get_a() {return a;}
void kolor_transparentny::set_a(int v) 
{
    if(invalid_color(v)) throw std::invalid_argument("Nieprawdlowa wartosc alfa");
    a = v;
}

//kolor nazwany
kolor_nazwany::kolor_nazwany() : kolor_nazwany("") {}
kolor_nazwany::kolor_nazwany(std::string _nazwa) : kolor_nazwany(0,0,0,0,_nazwa) {}
kolor_nazwany::kolor_nazwany(int _r, int _g, int _b, int _a, std::string _nazwa) : kolor_transparentny(_r,_g,_b,_a), nazwa(_nazwa)
{
    for(auto i : nazwa)
        if((i < 'a' || 'z' < i) && (i < 'A' || 'Z' < i))
            throw std::invalid_argument("Nieprawidlowa nazwa koloru: " + nazwa);
}

std::string kolor_nazwany::get_nazwa() {return nazwa;}
void kolor_nazwany::set_nazwa(const std::string &s) 
{
    for(auto i : s)
        if((i < 'a' || 'z' < i) && (i < 'A' || 'Z' < i))
            throw std::invalid_argument("Nieprawidlowa nazwa koloru: " + s);
    nazwa = s;
}