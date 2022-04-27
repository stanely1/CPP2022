#include "kolejka.hpp"
#include <stdexcept>

kolejka::kolejka() : kolejka(1) {}
kolejka::kolejka(int _pojemnosc) : pojemnosc(_pojemnosc)//, tab(new string[pojemnosc]) 
{
    if(pojemnosc <= 0) tab = nullptr, throw invalid_argument("zly rozmiar kolejki: " + to_string(pojemnosc));
    tab = new string[pojemnosc];
}
kolejka::kolejka(initializer_list<string> list) : kolejka(list.size())
{
    auto it = list.begin();
    for(int i = 0; i < pojemnosc; i++) tab[i] = *(it++);
    ile = pojemnosc;
}
kolejka::kolejka(kolejka &k) : kolejka(k.pojemnosc)
{
    poczatek = k.poczatek;
    ile = k.ile;
    copy(k.tab, k.tab+k.pojemnosc, tab);
}
kolejka::kolejka(kolejka &&k) : pojemnosc(k.pojemnosc), poczatek(k.poczatek), ile(k.ile), tab(k.tab)
{
    k.pojemnosc = k.poczatek = k.ile = 0;
    k.tab = nullptr;
}

kolejka::~kolejka() 
{
    delete[] tab;
}

kolejka& kolejka::operator=(const kolejka &k)
{
    if(this != &k)
    {
        this->~kolejka();
        pojemnosc = k.pojemnosc;
        poczatek = k.poczatek;
        ile = k.ile;
        tab = new string[pojemnosc];
        copy(k.tab, k.tab+pojemnosc, tab);
    }
    return *this;
}
kolejka& kolejka::operator=(kolejka &&k)
{
    if(this != &k) 
    {
        this->~kolejka();
        pojemnosc = k.pojemnosc;
        poczatek = k.poczatek;
        ile = k.ile;
        tab = k.tab;

        k.pojemnosc = k.poczatek = k.ile = 0;
        k.tab = nullptr;
    }
    return *this;
}

void kolejka::wstaw(string s)
{
    if(ile >= pojemnosc) return; //throw length_error("wstaw: przepelnienie kolejki");
    tab[(poczatek+ile)%pojemnosc] = s;
    ile++;
}
string kolejka::usun()
{
    if(ile == 0) return ""; //throw out_of_range("usun: kolejka pusta");
    string r = tab[poczatek++];
    ile--;
    if(poczatek == pojemnosc) poczatek = 0;
    return r;
}
string kolejka::zprzodu()
{
    //if(ile == 0) throw out_of_range("zprzodu: kolejka pusta");
    return ile ? tab[poczatek] : "";
}
int kolejka::dlugosc()
{
    return ile;
}