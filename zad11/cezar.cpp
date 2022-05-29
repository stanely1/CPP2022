#include "files.hpp"
#include <iostream>

const int CNT = 26;

void cezar(std::string &s, int d)
{
    d %= CNT;
    if(d < 0) d += CNT;
    for(auto &c : s)
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        {
            char r = 'a' <= c ? 'a' : 'A';
            c = (c-r+d)%CNT + r;
        }
}

int main(int argc, char **argv)
{
    if(argc != 4) return std::cerr << "Użycie: <plik wejsciowy> <plik wyjsciowy> <przesuniecie>\n", 0;
    try {
        wejscie in(argv[1]);
        wyjscie out(argv[2]);
        int d;
        try {
            d = std::stoi(argv[3]);
        } catch(std::invalid_argument &e) {
            return std::cerr << "Przesuniecie musi byc liczba calkowita!\n", 1;
        }

        std::string s;
        bool eof = false;
        while(!eof)
            try {
                s = in.nastlinia();
                cezar(s,d);
                out.piszlinie(s);
            } catch(std::ios_base::failure &e) {
                if(in.eof()) eof = true;
                else throw e;
            }
    } catch(std::ios_base::failure &e) {
        return std::cerr << e.what() << "\n", 1;
    }
}