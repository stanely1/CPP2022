#ifndef FILES_HPP
#define FILES_HPP

#include <fstream>

class wejscie {
    std::ifstream stream;
public:
    wejscie(std::string &filename);
    wejscie(const char *filename);
    ~wejscie();
    std::string nastlinia();
    bool eof();
};

class wyjscie {
    std::ofstream stream;
public:
    wyjscie(std::string &filename);
    wyjscie(const char *filename);
    ~wyjscie();
    void piszlinie(std::string &str);
    void piszlinie(const char *str);
};

#endif