#ifndef KOLEJKA_H
#define KOLEJKA_H

#include <string>
using namespace std;

class kolejka {
	int pojemnosc, poczatek = 0, ile = 0;
	string *tab;

public:
	kolejka();
	kolejka(int _pojemnosc);
	kolejka(initializer_list<string> list);
	kolejka(kolejka &k); 					// konstruktor kopiujący 
	kolejka(kolejka &&k); 					// konstruktor przenoszący

	~kolejka();

	kolejka& operator=(const kolejka &k); 	// przypisanie kopiujące
	kolejka& operator=(kolejka &&k);		// przypisanie przenoszące

	void wstaw(string s);
	string usun();
	string zprzodu();
	int dlugosc();
};

#endif
