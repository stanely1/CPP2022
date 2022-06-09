#ifndef IOS_MANIPULATORS_HPP
#define IOS_MANIPULATORS_HPP

#include <iostream>

// istream manipulators
std::istream & clearline(std::istream &is);
std::istream & ignore_whitespaces(std::istream &is);

class ignore {
private:
    int cnt;
public:
    ignore(int _cnt);
    std::istream & operator() (std::istream &is);
};

std::istream & operator >> (std::istream &is, ignore ig);

// ostream manipulators
std::ostream & quot(std::ostream &os);
std::ostream & amp(std::ostream &os);
std::ostream & lt(std::ostream &os);
std::ostream & gt(std::ostream &os);

class attr {
private:
    std::string key, val;
public:
    attr(std::string _key, std::string _val);
    std::ostream & operator() (std::ostream &os);
};

std::ostream & operator << (std::ostream &os, attr a);

#endif