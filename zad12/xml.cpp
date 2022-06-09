#include "xml.hpp"

using namespace xml_document;

// document 
document::document(const element &_root) : root(_root) {}

std::istream & xml_document::operator >> (std::istream &is, document &d) {return is >> d.root;}
std::ostream & xml_document::operator << (std::ostream &os, const document &d) {return os << d.root;}

// content
int content::level = 0;

content::content(text *_txt) : txt(_txt) {}
content::content(element *_elem) : elem(_elem) {}

std::istream & xml_document::operator >> (std::istream &is, content &c)
{
    return c.txt == nullptr ? is >> *c.elem : is >> *c.txt;
}
std::ostream & xml_document::operator << (std::ostream &os, const content &c)
{
    for(int i = 0; i < content::level; i++) os << "\t";
    return c.txt == nullptr ? os << *c.elem : os << *c.txt;
}

// element
element::element(const std::string &_name) : name(_name) {}

void element::add_content(const content &c) {body.push_back(c);}
void element::add_attribute(const attribute &a) {attrs.push_back(a);}
void element::add_attribute(const std::string &_name, const std::string &_value) 
{
    attrs.push_back(attribute(_name,_value));
}

std::istream & xml_document::operator >> (std::istream &is, element &e)
{
    char c;

    is >> ignore(1);
    while((c=is.get()) != '>' && !isspace(c)) e.name += c;
    is.putback(c);

    while((c = is.get()) != '>')
    {
        attribute a;
        is.putback(c) >> a;
        e.add_attribute(a);
    }

    is >> ignore_whitespaces;
    while((c=is.get()) != '/')
    {
        if(c == '<')
        {
            if((c = is.get()) == '/') break; // koniec elementu
            else 
            {
                is.putback(c), is.putback('<'); // podelement
                content x(new element);
                is >> x;
                e.add_content(x);
            }
        }
        else
        {
            content x(new text); // text
            is.putback(c) >> x;
            e.add_content(x);
        }
        is >> ignore_whitespaces;
    }
    return is >> ignore(e.name.size() + 1); // zamkniecie znacznika
}
std::ostream & xml_document::operator << (std::ostream &os, const element &e)
{
    os << lt << e.name;
    for(auto a : e.attrs) os << a;
    os << gt << "\n";
    content::level++;
    for(auto c : e.body) os << c << "\n";
    content::level--;
    for(int i = 0; i < content::level; i++) os << "\t";
    return os << lt << "/" << e.name << gt;
}

// attribute
attribute::attribute(const std::string &_name, const std::string &_value) : name(_name), value(_value) {}

std::istream & xml_document::operator >> (std::istream &is, attribute &a)
{
    is >> ignore_whitespaces;
    char c;
    while((c = is.get()) != '=') a.name += c;
    is >> ignore(1);
    while((c = is.get()) != '\"') a.value += c;

    return is;
}
std::ostream & xml_document::operator << (std::ostream &os, const attribute &a)
{
    return os << attr(a.name,a.value);
}

// text
text::text(const std::string &_str) : str(_str) {}

std::istream & xml_document::operator >> (std::istream &is, text &t)
{
    is >> ignore_whitespaces;
    char c;
    while((c=is.get()) != '<' && c != '\n') t.str += c;
    return is.putback(c);
}
std::ostream & xml_document::operator << (std::ostream &os, const text &t)
{
    return os << t.str;
}