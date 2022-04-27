#include "wielomian.hpp"

int main()
{
    wielomian f({1,2,3}); // 1 + 2 x + 3x^2 // initializer_list
    std::cout << f.get_deg() << "\n" << f << f(1) << " " << f(2) << " " << f(3) << "\n"; // wypisywanie i obliczanie wartosci

    std::cout << f[0] << " " << f[1] << " " << f[2] << "\n"; // dostęp - []
    f[0] = 3; f[1] = 1;                                      // przypisanie []
    std::cout << f << f[0] << " " << f[1] << " " << f[2] << "\n\n";

    std::cout << f*5; // mnozenie przez stala
    f *= 4;
    std::cout << f << "\n";

    /***************/

    wielomian g = wielomian(), gprim = wielomian(2), gbis = wielomian(3,5); // jednomian
    std::cout << g << gprim << gbis << "\n";

    std::cout << f+g << gprim-f << gbis*f << "\n"; // operacje na wielomianach

    g += f;
    std::cout << g; // 13 4 12
    f *= g;
    std::cout << f; //(12 + 4x + 12x^2) * (13 + 4x + 12x^2) - dziala
    gbis -= g;
    std::cout << gbis << "\n";

    wielomian h = f; // konstruktor kopiujacy
    std::cout << f << h << "\n";

    wielomian j = std::move(h); // konsturktor przenoszacy
    std::cout << "j: " << j << "h: " << h;

    j = gbis; // przypisanie kopiujace
    std::cout << "j: " << j << "gbis: " << gbis;

    f = std::move(g); // przypisanie przenoszące
    std::cout << "f: " << f << "g: " << g << "\n"; 
    
    double a[5] = {7, 6, 5, 4, 3};
    wielomian i(4,a); // konstruktor wielomianu
    std::cout << i;

    std::cin >> i; // wczytywanie z standardowego wejscia
    std::cout << i;

    try {
        wielomian w(-1);
    } catch(std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    try {
        std::cout << f[-1];
    } catch(std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    try {
        std::cout << f[f.get_deg()+1];
    } catch(std::exception &e) {
        std::cerr << e.what() << "\n";
    }
}