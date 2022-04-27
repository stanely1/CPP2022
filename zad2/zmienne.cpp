#include <stdexcept>
#include <iostream>
#include "zmienne.hpp"

zmienna::zmienna() : nazwa("_") {};
zmienna::zmienna(string _nazwa) : zmienna(_nazwa,0) {};
zmienna::zmienna(string _nazwa, double _wartosc) : nazwa(_nazwa), wartosc(_wartosc) 
{
    if(!name_valid()) throw invalid_argument("Nieprawidlowa nazwa zmiennej: " + nazwa);
}

bool zmienna::name_valid()
{
    if(nazwa.size() == 0) return false; // niepusty
    if('0' <= nazwa[0] && nazwa[0] <= '9') return false; // nie zaczyna sie od cyfry
    
    for(auto i : nazwa)
        if( !(('0' <= i && i <= '9') || ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z') || i == '_') ) return false;

    return true;
}

string zmienna::get_name()
{
    return nazwa;
}
double zmienna::get_val()
{
    return wartosc;
}
void zmienna::set_val(double _wartosc)
{
    wartosc = _wartosc;
}

zbior_zmiennych::zbior_zmiennych(const int _n) : n(_n), current_ind(0)
{
    if(n <= 0) tab = nullptr, throw invalid_argument("Zly rozmiar tablicy: " + to_string(n));
    tab = new zmienna[n];
}
zbior_zmiennych::~zbior_zmiennych()
{
    delete[] tab;
}

void zbior_zmiennych::wstaw(zmienna x)
{
    if(current_ind >= n) throw length_error("wstaw: przepelnienie tablicy");
    if(znajdz(x.get_name())) throw invalid_argument("wstaw: zmienna o tej nazwie juz jest w tablicy: " + x.get_name());

    tab[current_ind++] = x;
}
bool zbior_zmiennych::znajdz(string nazwa)
{
    for(int i = 0; i < current_ind; i++)
        if(tab[i].get_name() == nazwa) return true;
    return false;
}
void zbior_zmiennych::usun(string nazwa)
{
    for(int i = 0; i < current_ind; i++)
        if(tab[i].get_name() == nazwa) 
        {
            for(int j = i+1; j < current_ind; j++) //przesuwamy dalsza czesc tablicy o 1 w lewo;
                tab[j-1] = tab[j];
            current_ind--;
            return;
        }
    throw invalid_argument("usun: brak zmiennej w zbiorze: " + nazwa);

}
double zbior_zmiennych::get_val(string nazwa)
{
    for(int i = 0; i < current_ind; i++)
        if(tab[i].get_name() == nazwa) return tab[i].get_val();
    throw invalid_argument("get_val: brak zmiennej w zbiorze: " + nazwa);
}
void zbior_zmiennych::set_val(string nazwa, double wartosc)
{
    for(int i = 0; i < current_ind; i++)
        if(tab[i].get_name() == nazwa) return tab[i].set_val(wartosc); // czy mozna tak robic ??? (void)
    throw invalid_argument("set_val: brak zmiennej w zbiorze: " + nazwa);
}

void zbior_zmiennych::wypisz() 
{
    cout << '{';
    for(int i = 0; i < current_ind; i++)
        cout << tab[i].get_name() << " " << tab[i].get_val() << (i == current_ind-1 ? "" : "\n");
    cout << "}\n\n";
}