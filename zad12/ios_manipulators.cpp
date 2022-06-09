#include "ios_manipulators.hpp"

// istream
std::istream & clearline(std::istream &is)
{
    std::string d;
    return getline(is,d);
}
std::istream & ignore_whitespaces(std::istream &is)
{
    char c;
    while((c = is.get()) != EOF && isspace(c));
    return is.putback(c); 
}

ignore::ignore(int _cnt) : cnt(_cnt) {}
std::istream & ignore::operator() (std::istream &is)
{
    char c;
    while(cnt--)
        if((c = is.get()) == '\n' || c == EOF) break;
    return is;
}

std::istream & operator >> (std::istream &is, ignore ig) {return ig(is);}

// ostream
std::ostream & quot(std::ostream &os) {return os << '\"';}
std::ostream & amp(std::ostream &os)  {return os << '&';}
std::ostream & lt(std::ostream &os)   {return os << '<';}
std::ostream & gt(std::ostream &os)   {return os << '>';}

attr::attr(std::string _key, std::string _val) : key(_key), val(_val) {}
std::ostream & attr::operator() (std::ostream &os) 
{
    return os << ' ' << key << '=' << quot << val << quot;
}

std::ostream & operator << (std::ostream &os, attr a) {return a(os);}