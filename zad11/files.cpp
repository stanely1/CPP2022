#include "files.hpp"

wejscie::wejscie(std::string &filename) : stream(filename) 
{
    stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
}
wejscie::wejscie(const char *filename)  : stream(filename) 
{
    stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
}
wejscie::~wejscie() {stream.close();}
std::string wejscie::nastlinia()
{
    char c;
    std::string s;
    while((c = stream.get()) != '\n' && c != EOF) s += c;
    return s;
}
bool wejscie::eof() {return stream.eof();}

wyjscie::wyjscie(std::string &filename) : stream(filename) 
{
    stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
}
wyjscie::wyjscie(const char *filename)  : stream(filename) 
{
    stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
}
wyjscie::~wyjscie() {stream.close();}
void wyjscie::piszlinie(std::string &str)
{
    stream << str << "\n";
}
void wyjscie::piszlinie(const char *str)
{
    stream << str << "\n";
}