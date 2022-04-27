#ifndef TABBIT_HPP
#define TABBIT_HPP

#include <cstdint>
#include <iostream>

namespace obliczenia {
class tabbit {
    typedef uint64_t slowo;         // komorka w tablicy
    static const int rozmiarSlowa;  // rozmiar slowa w bitach

    friend std::istream & operator >> (std::istream &we, tabbit &tb);
    friend std::ostream & operator << (std::ostream &wy, const tabbit &tb);

    class ref {     // klasa pomocnicza do adresowania bitów
        int index;  // ktore slowo
        int shift;  // ktory bit w tym slowie
        const tabbit &t;

    public:
        ref(const tabbit &_t, int i);
        operator bool();
        operator bool() const;

        ref & operator = (const bool x);
        ref & operator = (const ref &x);
        //ref & operator = (ref&&);
    };  

protected:
    int liczba_slow; // liczba slow
    int dl;          // liczba bitów
    slowo *tab;      // tablica bitów

public:
    explicit tabbit(int rozm);  // wyzerowana tablica bitow [0...rozm]
    explicit tabbit(slowo tb);  // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
    tabbit(const tabbit &tb);   // konstruktor kopiujący
    tabbit(tabbit &&tb);        // konstruktor przenoszący
        
    ~tabbit();                  // destruktor

    tabbit& operator = (const tabbit &tb);  // przypisanie kopiujące
    tabbit& operator = (tabbit &&tb);       // przypisanie przenoszące

public:
    bool operator [] (int i) const; // indeksowanie dla stałych tablic bitowych
    ref  operator [] (int i);       // indeksowanie dla zwykłych tablic bitowych
    int rozmiar() const;            // rozmiar tablicy w bitach
    
public:
    // operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
    friend tabbit operator | (const tabbit &x, const tabbit &y);
    friend tabbit operator & (const tabbit &x, const tabbit &y);
    friend tabbit operator ^ (const tabbit &x, const tabbit &y);
    friend tabbit operator ! (const tabbit &x);

    tabbit& operator |= (const tabbit &x);
    tabbit& operator &= (const tabbit &x);
    tabbit& operator ^= (const tabbit &x);
};

//deklaracje operatorow
std::istream & operator >> (std::istream &we, tabbit &tb);
std::ostream & operator << (std::ostream &wy, const tabbit &tb);

tabbit operator | (const tabbit &x, const tabbit &y);
tabbit operator & (const tabbit &x, const tabbit &y);
tabbit operator ^ (const tabbit &x, const tabbit &y);
tabbit operator ! (const tabbit &x);
}

#endif