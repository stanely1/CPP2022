#include "wielomian.hpp"
#include <stdexcept>

wielomian::wielomian (int st, double wsp) : n(st), a(nullptr)     // konstruktor jednomianu
{
    if(st<0) throw std::invalid_argument("Ujemny stopien wielomianu");
    a = new double[st+1];
    a[0] = wsp;
} 
wielomian::wielomian (int st, const double wsp[]) : n(st), a(nullptr)       // konstruktor wielomianu
{
    if(st<0) throw std::invalid_argument("Ujemny stopien wielomianu");
    a = new double[st+1];
    std::copy(wsp,wsp+st+1,a);
}
wielomian::wielomian (std::initializer_list<double> wsp) : n(wsp.size()-1) // lista współczynników
{
    a = new double[n+1];
    std::copy(wsp.begin(),wsp.end(),a);
}
wielomian::wielomian (const wielomian &w) : wielomian(w.n,w.a) {} // konstruktor kopiujący
wielomian::wielomian (wielomian &&w) : n(w.n), a(w.a)               // konstruktor przenoszący
{
    w.a = nullptr;
    w.n = -1;
}

wielomian& wielomian::operator = (const wielomian &w)           // przypisanie kopiujące
{
    if(this != &w)
    {
        this->~wielomian();
        n = w.n;
        a = new double[n+1];
        std::copy(w.a,w.a+n+1,a);
    }
    return *this;
}
wielomian& wielomian::operator = (wielomian &&w)                // przypisanie przenoszące
{
    if(this != &w)
    {
        this->~wielomian();
        n = w.n;
        a = w.a;

        w.n = -1;
        w.a = nullptr;
    }
    return *this;
}

wielomian::~wielomian ()                                        // destruktor
{
    delete[] a;
}

std::istream& operator >> (std::istream &we, wielomian &w)
{
    for(int i = 0; i <= w.n; i++) we >> w.a[i];
    return we;
}
std::ostream& operator << (std::ostream &wy, const wielomian &w)
{
    for(int i = 0; i <= w.n; i++) wy << w.a[i] << " ";
    wy << "\n";
    return wy;
}

wielomian operator + (const wielomian &u, const wielomian &v)
{
    int st = std::max(u.n, v.n);
    double ra[st+1];
    for(int i = 0; i <= st; i++)
        if(i <= u.n && i <= v.n) ra[i] = u.a[i] + v.a[i];
        else if(i <= u.n) ra[i] = u.a[i];
        else ra[i] = v.a[i];
    
    return wielomian(st,ra);
}
wielomian operator - (const wielomian &u, const wielomian &v)
{
    int st = std::max(u.n, v.n);
    double ra[st+1];
    for(int i = 0; i <= st; i++)
        if(i <= u.n && i <= v.n) ra[i] = u.a[i] - v.a[i];
        else if(i <= u.n) ra[i] = u.a[i];
        else ra[i] = -v.a[i];
    
    return wielomian(st,ra);
}
wielomian operator * (const wielomian &u, const wielomian &v)
{
    int st = u.n + v.n;
    double ra[st+1];
    std::fill(ra,ra+st+1,0);

    for(int i = 0; i <= u.n; i++)
        for(int j = 0; j <= v.n; j++)
            ra[i+j] += u.a[i]*v.a[j];
            
    return wielomian(st,ra);
}

wielomian operator * (const wielomian &u, double c)
{
    double ra[u.n+1];
    for(int i = 0; i <= u.n; i++) ra[i] = u.a[i]*c;
    return wielomian(u.n,ra);
}
wielomian& wielomian::operator += (const wielomian &v)
{
    *this = *this + v;
    return *this;
}
wielomian& wielomian::operator -= (const wielomian &v)
{
    *this = *this - v;
    return *this;   
}
wielomian& wielomian::operator *= (const wielomian &v)
{
    *this = *this * v;
    return *this;
}
wielomian& wielomian::operator *= (double c)
{
    *this = *this * c;
    return *this;
}
double wielomian::operator () (double x) const                  // wartość wielomianu dla x
{
    double res = 0;
    for(int i = n; i >= 0; i--) res = res*x + a[i];
    return res;
}
double wielomian::operator [] (int i) const                     // do odczytu współczynnika
{
    if(i < 0 || n < i) throw std::out_of_range("index poza zakresem");
    return a[i];
}
double& wielomian::operator [] (int i)                          // do zapisu współczynnika
{
    if(i < 0 || n < i) throw std::out_of_range("index poza zakresem");
    return a[i];
}

int wielomian::get_deg() 
{
    return n;
}