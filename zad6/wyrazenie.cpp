#include "wyrazenie.hpp"
#include <stdexcept>
#include <cmath>

wyrazenie::wyrazenie(std::string _typ) : typ(_typ) {}
std::string wyrazenie::get_typ() {return typ;}

liczba::liczba(double _val) : wyrazenie("liczba"), val(_val) {}
double liczba::oblicz() {return val;}
std::string liczba::zapis() {return std::to_string(val);}

//stale
stala::stala(std::string _nazwa, double _val) : wyrazenie("stala"), nazwa(_nazwa), val(_val) {}
double stala::oblicz() {return val;}
std::string stala::zapis() {return nazwa;}

pi::pi() : stala("pi",M_PI) {}
e::e() : stala("e",M_E) {}
fi::fi() : stala("fi",1.618033988749) {}

std::vector<std::pair<std::string,double>> zmienna::vals;

zmienna::zmienna(std::string _nazwa) : wyrazenie("zmienna"), nazwa(_nazwa) {}
double zmienna::oblicz()
{
    return get_val(nazwa);
    throw std::invalid_argument("Brak wartosci zmiennej: " + nazwa);
}
std::string zmienna::zapis() {return nazwa;}

void zmienna::add_val(std::string _nazwa, double val) 
{
    for(auto i : vals)
        if(i.first == _nazwa) throw std::invalid_argument("zmienna jest juz w zbiorze: " + _nazwa);
    vals.push_back({_nazwa,val});
}
void zmienna::set_val(std::string _nazwa, double val)
{
    for(auto &p : vals) 
        if(p.first == _nazwa) {p.second = val; return;}
    throw std::invalid_argument("brak zmiennej w zbiorze: " + _nazwa);
}
void zmienna::remove_val(std::string _nazwa)
{
    for(int i = 0; i < vals.size(); i++)
        if(vals[i].first == _nazwa) {vals.erase(vals.begin()+i); return;}
    throw std::invalid_argument("brak zmiennej w zbiorze: " + _nazwa);
}
double zmienna::get_val(std::string _nazwa)
{
    for(auto i : vals)
        if(i.first == _nazwa) return i.second;
    throw std::invalid_argument("brak zmiennej w zbiorze: " + _nazwa);
}

//operatoty unarne
operator1arg::operator1arg(wyrazenie *_op1, std::string _typ) : wyrazenie(_typ), op1(_op1) {}

sin::sin(wyrazenie *_op1) : operator1arg(_op1,"sin") {}
cos::cos(wyrazenie *_op1) : operator1arg(_op1,"cos") {}
exp::exp(wyrazenie *_op1) : operator1arg(_op1,"exp") {}
ln ::ln (wyrazenie *_op1) : operator1arg(_op1, "ln") {}
Abs::Abs(wyrazenie *_op1) : operator1arg(_op1,"Abs") {}
neg::neg(wyrazenie *_op1) : operator1arg(_op1,"neg") {}
inv::inv(wyrazenie *_op1) : operator1arg(_op1,"inv") {}

double sin::oblicz() {return std::sin(op1->oblicz());}
double cos::oblicz() {return std::cos(op1->oblicz());}
double exp::oblicz() {return std::exp(op1->oblicz());}
double  ln::oblicz() {return std::log(op1->oblicz());}
double Abs::oblicz() {return std::abs(op1->oblicz());}
double neg::oblicz() {return   -(op1->oblicz());}
double inv::oblicz() {return  1/(op1->oblicz());}

std::string sin::zapis() {return "sin(" + op1->zapis() + ")";}
std::string cos::zapis() {return "cos(" + op1->zapis() + ")";}
std::string  ln::zapis() {return  "ln(" + op1->zapis() + ")";}
std::string Abs::zapis() {return    "|" + op1->zapis() + "|";}
std::string exp::zapis() 
{
    if(op1->get_typ() == "neg" || 
       op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "mod" ||
       op1->get_typ() == "inv" ||
       op1->get_typ() == "mult"||
       op1->get_typ() == "Div") return "e^(" + op1->zapis() + ")";
    else return "e^" + op1->zapis();
}
std::string neg::zapis() 
{
    if(op1->get_typ() == "neg" || 
       op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "mod") return "-(" + op1->zapis() + ")";
    else return "-" + op1->zapis();
}
std::string inv::zapis() 
{
    if(op1->get_typ() == "neg" || 
       op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "mod" ||
       op1->get_typ() == "inv" ||
       op1->get_typ() == "mult"||
       op1->get_typ() == "Div") return "1/(" + op1->zapis() + ")";
    else return "1/" + op1->zapis();
}

//operatory binarne
operator2arg::operator2arg(wyrazenie *_op1, wyrazenie *_op2, std::string _typ) : operator1arg(_op1,_typ), op2(_op2) {}

add::add  (wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2, "add") {}
sub::sub  (wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2, "sub") {}
mult::mult(wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2,"mult") {}
Div::Div  (wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2, "Div") {}
mod::mod  (wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2, "mod") {}
log::log  (wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2, "log") {}
pow::pow  (wyrazenie *_op1, wyrazenie *_op2) : operator2arg(_op1,_op2, "pow") {}

double add::oblicz()  {return op1->oblicz() + op2->oblicz();}
double sub::oblicz()  {return op1->oblicz() - op2->oblicz();}
double mult::oblicz() {return op1->oblicz() * op2->oblicz();}
double Div::oblicz()  {return op1->oblicz() / op2->oblicz();}
double log::oblicz()  {return std::log(op2->oblicz()) / std::log(op1->oblicz());} // log_x(y) = log(y)/log(x)
double pow::oblicz()  {return std::pow(op1->oblicz(), op2->oblicz());}
double mod::oblicz()  
{
    double x = op1->oblicz();
    double y = op2->oblicz();
    if(x != (long)x || y != (long)y) throw std::invalid_argument("mod: operandy musza byc calkowite");
    return (long)x % (long)y;
}

std::string add::zapis() 
{
    return op2->get_typ() == "neg" ? op1->zapis() + "+(" + op2->zapis() + ")" : 
                                     op1->zapis() + "+" + op2->zapis();
}
std::string sub::zapis() 
{
    std::string z2 = op2->zapis();
    if(op2->get_typ() == "add" ||
       op2->get_typ() == "sub" ||
       op2->get_typ() == "neg") z2 = "(" + z2 + ")";
    
    return op1->zapis() + "-" + z2;
}
std::string mult::zapis()
{
    std::string z1 = op1->zapis();
    std::string z2 = op2->zapis();

    if(op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "Div" ||
       op1->get_typ() == "mod" ||
       op1->get_typ() == "inv") z1 = "(" + z1 + ")";
    
    if(op2->get_typ() == "add" ||
       op2->get_typ() == "sub" ||
       op2->get_typ() == "mod" ||
       op2->get_typ() == "neg") z2 = "(" + z2 + ")";

    return z1 + "*" + z2;
}
std::string Div::zapis()
{
    std::string z1 = op1->zapis();
    std::string z2 = op2->zapis();

    if(op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "Div" ||
       op1->get_typ() == "mod" ||
       op1->get_typ() == "inv") z1 = "(" + z1 + ")";
    
    if(op2->get_typ() == "add" ||
       op2->get_typ() == "sub" ||
       op2->get_typ() == "mod" ||
       op2->get_typ() == "neg" ||
       op2->get_typ() == "mult"||
       op2->get_typ() == "Div" ||
       op2->get_typ() == "inv") z2 = "(" + z2 + ")";

    return z1 + "/" + z2;
}
std::string mod::zapis()
{
    std::string z1 = op1->zapis();
    std::string z2 = op2->zapis();

    if(op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "mod") z1 = "(" + z1 + ")";
    
    if(op2->get_typ() == "add" ||
       op2->get_typ() == "sub" ||
       op2->get_typ() == "mod" ||
       op2->get_typ() == "neg") z2 = "(" + z2 + ")";

    return z1 + "%" + z2;
}
std::string log::zapis()
{
    std::string z1 = op1->zapis();

    if(op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "Div" ||
       op1->get_typ() == "mod" ||
       op1->get_typ() == "inv" ||
       op1->get_typ() == "mult"||
       op1->get_typ() == "exp" ||
       op1->get_typ() == "pow" ||
       op1->get_typ() == "neg") z1 = "{" + z1 + "}";

    return "log_" + z1 + "(" + op2->zapis() + ")";
}
std::string pow::zapis()
{
    std::string z1 = op1->zapis();
    std::string z2 = op2->zapis();

    if(op1->get_typ() == "add" ||
       op1->get_typ() == "sub" ||
       op1->get_typ() == "Div" ||
       op1->get_typ() == "mult"||
       op1->get_typ() == "mod" ||
       op1->get_typ() == "inv" ||
       op1->get_typ() == "pow" ||
       op1->get_typ() == "exp" ||
       op1->get_typ() == "neg") z1 = "(" + z1 + ")";
    
    if(op2->get_typ() == "add" ||
       op2->get_typ() == "sub" ||
       op2->get_typ() == "mod" ||
       op2->get_typ() == "neg" ||
       op2->get_typ() == "mult"||
       op2->get_typ() == "Div" ||
       op2->get_typ() == "inv") z2 = "(" + z2 + ")";

    return z1 + "^" + z2;
}