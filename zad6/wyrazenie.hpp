#ifndef WYRAZENIE_HPP
#define WYRAZENIE_HPP

#include <string>
#include <vector>

class wyrazenie {
protected:
    std::string typ;
public:
    wyrazenie(std::string _typ);
    std::string get_typ();
    virtual double oblicz() = 0;
    virtual std::string zapis() = 0;

    wyrazenie& operator = (const wyrazenie&) = delete;
    wyrazenie& operator = (wyrazenie&&) = delete;
    wyrazenie(const wyrazenie&) = delete;
    wyrazenie(wyrazenie&&) = delete; 
};

class liczba : public wyrazenie {
    double val;
public:
    liczba(double _val);
    double oblicz() override;
    std::string zapis() override;
};

// stale
class stala : public wyrazenie {
protected:
    std::string nazwa;
    double val;
public:
    stala(std::string _nazwa, double _val);
    double oblicz() override;
    std::string zapis() override;
};

class pi : public stala {
public:
    pi();
};
class e : public stala {
public:
    e();
};
class fi : public stala {
public:
    fi();
};

class zmienna : public wyrazenie {
    std::string nazwa;
    static std::vector<std::pair<std::string,double>> vals;
public:
    zmienna(std::string _nazwa);
    double oblicz() override;
    std::string zapis() override;

    static void add_val(std::string _nazwa, double val);
    static void set_val(std::string _nazwa, double val);
    static void remove_val(std::string _nazwa);
    static double get_val(std::string _nazwa);
};

//operatory 1-arne
class operator1arg : public wyrazenie {
protected:
    wyrazenie *op1;
public:
    operator1arg(wyrazenie *_op1, std::string _typ = "operator1arg");
};

class sin : public operator1arg {
public:
    sin(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};
class cos : public operator1arg {
public:
    cos(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};
class exp : public operator1arg {
public:
    exp(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};
class ln : public operator1arg {
public:
    ln(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};
class Abs : public operator1arg {
public:
    Abs(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};
class neg : public operator1arg {
public:
    neg(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};
class inv : public operator1arg {
public:
    inv(wyrazenie *_op1);
    double oblicz() override;
    std::string zapis() override;
};

// operatory binarne
class operator2arg : public operator1arg {
protected:
    wyrazenie *op2;
public:
    operator2arg(wyrazenie *_op1, wyrazenie *_op2, std::string _typ = "operator2arg");
};

class add : public operator2arg {
public:
    add(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};
class sub : public operator2arg {
public:
    sub(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};
class mult : public operator2arg {
public:
    mult(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};
class Div : public operator2arg {
public:
    Div(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};
class mod : public operator2arg {
public:
    mod(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};
class log : public operator2arg {
public:
    log(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};
class pow : public operator2arg {
public:
    pow(wyrazenie *_op1, wyrazenie *_op2);
    double oblicz() override;
    std::string zapis() override;
};

#endif