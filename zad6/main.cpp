#include "wyrazenie.hpp"
#include <iostream>
using namespace std;

int main()
{
    wyrazenie *w = new sub(new pi(), new add(new liczba(2), new mult(new zmienna("x"), new liczba(7))));
    zmienna::add_val("x",5);
    cout << w->zapis() << " = " << w->oblicz() << "\n";

    wyrazenie *w2 = new Div(new mult(new sub(new zmienna("x"),
                                             new liczba(1)),
                                     new zmienna("x")), new liczba(2));
    cout << w2->zapis() << " = " << w2->oblicz() << "\n";

    wyrazenie *tab[10];
    tab[0] = new Div(new add(new liczba(3), new liczba(5)),
                     new add(new liczba(2), new mult(new zmienna("x"), new liczba(7))));
    tab[1] = new sub(new add(new liczba(2), new mult(new zmienna("x"), new liczba(7))),
                     new add(new mult(new zmienna("y"), new liczba(3)), new liczba(5)));
    tab[2] = new Div(new cos(new mult(new add(new zmienna("x"), new liczba(1)), new pi())),
                     new exp(new pow(new zmienna("x"), new liczba(2))));

    zmienna::add_val("y",90);
    for(double d = 0; d <= 1; d+=0.1)
    {
        zmienna::set_val("x",d);
        zmienna::set_val("y",d);
        cout << "x = " << zmienna::get_val("x") << ", y = " << zmienna::get_val("y") << "\n";
        for(int i = 0; i <= 2; i++)
            cout << tab[i]->zapis() << " = " << tab[i]->oblicz() << "\n";
        cout << "\n";
    } 

    tab[3] = new neg(new sub(new ln(new Abs(new add(new liczba(1), new zmienna("x")))), 
                             new inv(new mult(new sin(new fi()), new exp(new liczba(7))))));

    tab[4] = new log(new mod(new add(new liczba(4), new liczba(7)),
                             new liczba(17)),
                     new pow(new e(), new zmienna("x")));
    tab[5] = new add(new Abs(new inv(new neg(new liczba(5)))), 
                     new log(new liczba(2), new liczba(16)));
    for(int i = 3; i <= 5; i++)
        cout << tab[i]->zapis() << " = " << tab[i]->oblicz() << "\n";

    // *tab[0] = *tab[1];
    // liczba x(43);
    // liczba y(x);
}