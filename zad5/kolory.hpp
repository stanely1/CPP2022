#ifndef KOLORY_HPP
#define KOLORY_HPP

#include <string>

class kolor {
protected:
    int r, g, b;
public:
    kolor();
    kolor(int _r, int _g, int _b);

    int get_r();
    int get_g();
    int get_b();
    void set_r(int v);
    void set_g(int v);
    void set_b(int v);

    static kolor sum(kolor a, kolor b);
};

class kolor_transparentny : public kolor {
protected:
    int a;
public:
    kolor_transparentny();
    kolor_transparentny(int _r, int _g, int _b, int _a);

    int get_a();
    void set_a(int v);
};

class kolor_nazwany : public kolor_transparentny {
protected:
    std::string nazwa;
public:
    kolor_nazwany();
    kolor_nazwany(std::string _nazwa);
    kolor_nazwany(int _r, int _g, int _b, int _a, std::string _nazwa);

    std::string get_nazwa();
    void set_nazwa(const std::string &s);
};

#endif