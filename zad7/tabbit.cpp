#include "tabbit.hpp"

using namespace obliczenia;

const int tabbit::rozmiarSlowa = 8*sizeof(tabbit::slowo); // w bitach

std::istream & obliczenia::operator >> (std::istream &we, tabbit &tb)
{
    std::string s;
    we >> s; 
    if((int)s.size() != tb.dl) throw std::invalid_argument("Nieprawidlowe dane");
    for(int i = 0; i < tb.dl; i++) {
        if(s[i] == '0') tb[i] = 0;
        else if(s[i] == '1') tb[i] = 1;
        else throw std::invalid_argument("Nieprawidlowe dane");
    }
    return we;
}

std::ostream & obliczenia::operator << (std::ostream &wy, const tabbit &tb)
{
    for(int i = 0; i < tb.dl; i++)
        wy << tb[i];
    return wy;
}

// ref
tabbit::ref::ref(const tabbit &_t, int i) : t(_t)
{
    index = i/rozmiarSlowa;
    shift = i%rozmiarSlowa; 
}
tabbit::ref::operator bool()
{
    return t.tab[index] & ((slowo)1 << shift);
}
tabbit::ref::operator bool() const
{
    return t.tab[index] & ((slowo)1 << shift);
}

tabbit::ref & tabbit::ref::operator = (const bool x) {
    x ? t.tab[index] |= (slowo)1 << shift : t.tab[index] &= ~((slowo)1 << shift);
    return *this;
}
tabbit::ref & tabbit::ref::operator = (const ref &x)
{
    return *this = (bool)x;
}

//konstruktory
tabbit::tabbit(int rozm) : liczba_slow((rozm+rozmiarSlowa-1)/rozmiarSlowa), dl(rozm), tab(nullptr)
{
    if(rozm <= 0) throw std::invalid_argument("Rozmiar tablicy musi byc dodatni");
    tab = new slowo[liczba_slow];
    std::fill(tab,tab+liczba_slow,0);
}
tabbit::tabbit(slowo tb) : liczba_slow(1), dl(rozmiarSlowa), tab(new slowo)
{
    *tab = tb;
} 
tabbit::tabbit(const tabbit &tb) : liczba_slow(tb.liczba_slow), dl(tb.dl), tab(new slowo[liczba_slow])
{
    std::copy(tb.tab,tb.tab+liczba_slow,tab);
}
tabbit::tabbit(tabbit &&tb) : liczba_slow(tb.liczba_slow), dl(tb.dl), tab(tb.tab)
{
    tb.liczba_slow = tb.dl = 0;
    tb.tab = nullptr;
}
    
tabbit::~tabbit()
{
    delete[] tab;
}

// operatory
tabbit& tabbit::operator = (const tabbit &tb)
{
    if(this != &tb)
    {
        this->~tabbit();
        liczba_slow = tb.liczba_slow;
        dl = tb.dl;
        tab = new slowo[liczba_slow];
        std::copy(tb.tab,tb.tab+liczba_slow,tab);
    }
    return *this;
}
tabbit& tabbit::operator = (tabbit &&tb)
{
    if(this != &tb)
    {
        this->~tabbit();
        liczba_slow = tb.liczba_slow;
        dl = tb.dl;
        tab = tb.tab;

        tb.liczba_slow = tb.dl = 0;
        tb.tab = nullptr;
    }
    return *this;
}

bool tabbit::operator [] (int i) const
{
    if(i < 0 || dl <= i) throw std::out_of_range("");
    return (bool)tabbit::ref(*this,i);
}
tabbit::ref tabbit::operator [] (int i)
{
    if(i < 0 || dl <= i) throw std::out_of_range("");
    return tabbit::ref(*this,i);
}
int tabbit::rozmiar() const
{
    return dl;
}

//operatory bitowe
tabbit obliczenia::operator | (const tabbit &x, const tabbit &y)
{
    tabbit t = tabbit(std::max(x.dl,y.dl));
    for(int i = 0; i < t.liczba_slow; i++)
        if(x.liczba_slow <= i) t.tab[i] = y.tab[i];
        else if(y.liczba_slow <= i) t.tab[i] = x.tab[i];
        else t.tab[i] = x.tab[i] | y.tab[i];
    return t;
}
tabbit obliczenia::operator & (const tabbit &x, const tabbit &y)
{
    tabbit t = tabbit(std::max(x.dl,y.dl));
    for(int i = 0; i < t.liczba_slow; i++)
        if(x.liczba_slow <= i || y.liczba_slow <= i) t.tab[i] = 0;
        else t.tab[i] = x.tab[i] & y.tab[i];
    return t;
}
tabbit obliczenia::operator ^ (const tabbit &x, const tabbit &y)
{
    tabbit t = tabbit(std::max(x.dl,y.dl));
    for(int i = 0; i < t.liczba_slow; i++)
        if(x.liczba_slow <= i) t.tab[i] = y.tab[i];
        else if(y.liczba_slow <= i) t.tab[i] = x.tab[i];
        else t.tab[i] = x.tab[i] ^ y.tab[i];
    return t;
}
tabbit obliczenia::operator ! (const tabbit &x)
{
    tabbit t = tabbit(x.dl);
    for(int i = 0; i < t.liczba_slow; i++) t.tab[i] = ~x.tab[i];
    return t;
}

tabbit& tabbit::operator |= (const tabbit &x)
{
    return *this = *this | x;
}
tabbit& tabbit::operator &= (const tabbit &x)
{
    return *this = *this & x;
}
tabbit& tabbit::operator ^= (const tabbit &x)
{
    return *this = *this ^ x;
}
