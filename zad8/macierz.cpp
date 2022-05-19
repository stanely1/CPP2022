#include "macierz.hpp"
using namespace obliczenia;

// wektor
wektor::wektor(int _size) : size(_size) 
{
    if(size <= 0) throw invalid_vector_size("rozmiar wektora musi byc dotatni!");
    tab = new double[size] {}; // uniform initialization
}
wektor::wektor(std::initializer_list<double> l) : size(l.size())
{
    tab = new double[size];
    std::copy(l.begin(),l.end(),tab);
}
wektor::wektor(const wektor &x) : size(x.size), tab(new double[x.size])   // konstruktor kopiujący
{
    std::copy(x.tab,x.tab+size,tab);
}
wektor::wektor(wektor &&x) : size(x.size), tab(x.tab)                   // konstruktor przenoszący
{
    x.tab = nullptr;
}

wektor::~wektor()
{
    delete[] tab;
}

wektor & wektor::operator = (const wektor &x)   // przypisanie kopiujące
{
    if(size != x.size) throw invalid_vector_size("wektory maja rozne rozmiary");
    if(this != &x)
    {
        // this->~wektor();         // nie trzeba, bo mamy staly rozmiar
        // tab = new double[size];
        std::copy(x.tab,x.tab+size,tab);
    }
    return *this;
}
wektor & wektor::operator = (wektor &&x)        // przypisanie przenoszące
{
    if(size != x.size) throw invalid_vector_size("wektory maja rozne rozmiary");
    if(this != &x)
    {
        this->~wektor();
        tab = x.tab;
        x.tab = nullptr;
    }
    return *this;
}

double wektor::operator [] (int i) const
{
    if(i < 0 || size <= i) throw std::out_of_range("");
    return tab[i];
}
double & wektor::operator [] (int i)
{
    if(i < 0 || size <= i) throw std::out_of_range("");
    return tab[i];
}

std::istream & obliczenia::operator >> (std::istream &is, wektor &w)
{
    for(int i = 0; i < w.size; i++) is >> w.tab[i];
    return is;
}
std::ostream & obliczenia::operator << (std::ostream &os, const wektor &w)
{
    for(int i = 0; i < w.size; i++) os << w.tab[i] << " ";
    return os;
}

wektor obliczenia::operator-(const wektor &v) // zmiana znaku
{
    wektor r(v.size);
    for(int i = 0; i < r.size; i++) r.tab[i] = -v.tab[i];
    return r;
}
wektor obliczenia::operator+(const wektor &x, const wektor &y)
{
    if(x.size != y.size) throw invalid_vector_size("+: wektory musza miec ten sam rozmiar");
    wektor r(x);
    for(int i = 0; i < r.size; i++) r.tab[i] += y.tab[i];
    return r;
}
wektor obliczenia::operator-(const wektor &x, const wektor &y)
{
    if(x.size != y.size) throw invalid_vector_size("-: wektory musza miec ten sam rozmiar");
    wektor r(x);
    for(int i = 0; i < r.size; i++) r.tab[i] -= y.tab[i];
    return r;
}
wektor obliczenia::operator*(const wektor &v, double d)          // mnozenie przez stala
{
    wektor r(v.size);
    for(int i = 0; i < r.size; i++) r.tab[i] = v.tab[i] * d;
    return r;
}
wektor obliczenia::operator*(double d, const wektor &v)          // mnozenie przez stala
{
    wektor r(v.size);
    for(int i = 0; i < r.size; i++) r.tab[i] = v.tab[i] * d;
    return r;
}
double obliczenia::operator*(const wektor &x, const wektor &y)   // iloczyn skalarny x*y
{
    if(x.size != y.size) throw invalid_vector_size("*: wektory musza miec ten sam rozmiar");
    double r = 0;
    for(int i = 0; i < x.size; i++) r += x.tab[i] * y.tab[i];
    return r;
}

wektor & wektor::operator+=(const wektor &v)
{
    return *this = *this + v;
}
wektor & wektor::operator-=(const wektor &v)
{
    return *this = *this - v;
}
wektor & wektor::operator*=(double d)
{
    return *this = *this * d;
}

int wektor::get_size() const
{
    return size;
}

// macierz
macierz::macierz(int _rows, int _cols) : rows(_rows), cols(_cols) // wiersz = wektor
{
    if(rows <= 0) throw invalid_matrix_size("liczba wierszy musi byc dodatnia");
    tab = new wektor*[rows];
    for(int i = 0; i < rows; i++) tab[i] = new wektor(cols);
}
macierz::macierz(std::initializer_list<wektor> l) : rows(l.size()), cols(l.begin()->get_size())
{
    tab = new wektor*[rows];
    auto it = l.begin();
    for(int i = 0; i < rows; i++, it++) tab[i] = new wektor(*it);
}
macierz::macierz(const macierz &x) : cols(x.cols), rows(x.rows), tab(new wektor*[x.rows])  // konstruktor kopiujący
{
    for(int i = 0; i < rows; i++) tab[i] = new wektor(*x.tab[i]);
}
macierz::macierz(macierz &&x) : cols(x.cols), rows(x.rows), tab(x.tab)                   // konsturktor przenoszący
{
    x.tab = nullptr;
}

macierz::~macierz()
{
    if(this->tab == nullptr) return;
    for(int i = 0; i < rows; i++) delete tab[i];
    delete[] tab;
}

macierz & macierz::operator = (const macierz &x)     // przypisanie kopiujące
{
    if(x.cols != cols || x.rows != rows) throw invalid_matrix_size("macierze maja rozne rozmiary");
    if(this != &x)
    {
        this->~macierz();
        tab = new wektor*[rows];
        for(int i = 0; i < rows; i++) tab[i] = new wektor(*x.tab[i]);
    }
    return *this;
}
macierz & macierz::operator = (macierz &&x)          // przypisanie przenoszące
{
    if(x.cols != cols || x.rows != rows) throw invalid_matrix_size("macierze maja rozne rozmiary");
    if(this != &x)
    {
        this->~macierz();
        tab = x.tab;
        x.tab = nullptr;
    }
    return *this;
}

wektor & macierz::operator [] (int i) const
{
    if(i < 0 || rows <= i) throw std::out_of_range("");
    return *tab[i];
}
wektor & macierz::operator [] (int i)
{
    if(i < 0 || rows <= i) throw std::out_of_range("");
    return *tab[i];
}

std::istream & obliczenia::operator >> (std::istream &is, macierz &m)
{
    for(int i = 0; i < m.rows; i++) is >> *m.tab[i];
    return is;
}
std::ostream & obliczenia::operator << (std::ostream &os, const macierz &m)
{
    for(int i = 0; i < m.rows; i++) os << *m.tab[i] << "\n";
    return os;
}

macierz obliczenia::operator-(const macierz &m) // zmiana znaku
{
    macierz r(m.rows,m.cols);
    for(int i = 0; i < r.rows; i++) *r.tab[i] = -*m.tab[i];
    return r;
}
macierz obliczenia::operator+(const macierz &p, const macierz &q)
{
    if(p.rows != q.rows || p.cols != q.cols) throw invalid_matrix_size("+: macierze musza miec ten sam rozmiar");
    macierz r(p);
    for(int i = 0; i < p.rows; i++) *r.tab[i] += *q.tab[i];
    return r;
}
macierz obliczenia::operator-(const macierz &p, const macierz &q)
{
    if(p.rows != q.rows || p.cols != q.cols) throw invalid_matrix_size("-: macierze musza miec ten sam rozmiar");
    macierz r(p);
    for(int i = 0; i < p.rows; i++) *r.tab[i] -= *q.tab[i];
    return r;
}
macierz obliczenia::operator*(const macierz &m, double d)
{
    macierz r(m.rows,m.cols);
    for(int i = 0; i < r.rows; i++) *r.tab[i] = *m.tab[i] * d;
    return r;
}
macierz obliczenia::operator*(double d, const macierz &m)
{
    macierz r(m.rows,m.cols); 
    for(int i = 0; i < r.rows; i++) *r.tab[i] = *m.tab[i] * d;
    return r;
}
macierz obliczenia::operator*(const macierz &p, const macierz &q)
{
    if(p.cols != q.rows) throw invalid_matrix_size("*: zly rozmiar macierzy");
    macierz r(p.rows,q.cols);
    for(int i = 0; i < r.rows; i++)
        for(int j = 0; j < r.cols; j++)
            for(int k = 0; k < p.cols; k++)
                r[i][j] += p[i][k] * q[k][j];
    return r;
}
macierz obliczenia::operator~(const macierz &m) // transpozycja
{
    macierz r(m.cols,m.rows);
    for(int i = 0; i < r.rows; i++)
        for(int j = 0; j < r.cols; j++)
            r[i][j] = m[j][i];
    return r;
}

macierz & macierz::operator+=(const macierz &m)
{
    return *this = *this + m;
}
macierz & macierz::operator-=(const macierz &m)
{
    return *this = *this - m;
}
macierz & macierz::operator*=(double d)
{
    return *this = *this * d;
}
