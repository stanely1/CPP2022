#ifndef XML_HPP
#define XML_HPP

#include <vector>
#include "ios_manipulators.hpp"

namespace xml_document {
    class document;
    class content;
    class element;
    class attribute;
    class text;

    class content {
    protected:
        text *txt = nullptr;
        element *elem = nullptr;
    public:
        static int level;
        content(text *_txt);
        content(element *_elem);
        friend std::istream & operator >> (std::istream &is, content &c);
        friend std::ostream & operator << (std::ostream &os, const content &c); 
    };

    class element {
    protected:
        std::string name;
        std::vector<attribute> attrs;
        std::vector<content> body;
    public:
        element() = default;
        element(const std::string &_name);
        void add_content(const content &c);
        void add_attribute(const attribute &a);
        void add_attribute(const std::string &_name, const std::string &_value);
        friend std::istream & operator >> (std::istream &is, element &e);
        friend std::ostream & operator << (std::ostream &os, const element &e);
    };

    class attribute {
    protected:
        std::string name, value;
    public:
        attribute() = default;
        attribute(const std::string &_name, const std::string &_value);
        friend std::istream & operator >> (std::istream &is, attribute &a);
        friend std::ostream & operator << (std::ostream &os, const attribute &a);
    };

    class document {
    protected:
        element root;
    public:
        document(const element &_root);
        friend std::istream & operator >> (std::istream &is, document &d);
        friend std::ostream & operator << (std::ostream &os, const document &d);
    };

    class text {
    protected:
        std::string str;
    public:
        text() = default;
        text(const std::string &_str);
        friend std::istream & operator >> (std::istream &is,text &t);
        friend std::ostream & operator << (std::ostream &os, const text &t);
    };

    std::istream & operator >> (std::istream &is, document &d);
    std::ostream & operator << (std::ostream &os, const document &d);
    std::istream & operator >> (std::istream &is, content &c);
    std::ostream & operator << (std::ostream &os, const content &c);
    std::istream & operator >> (std::istream &is, element &e);
    std::ostream & operator << (std::ostream &os, const element &e);
    std::istream & operator >> (std::istream &is, attribute &a);
    std::ostream & operator << (std::ostream &os, const attribute &a);
    std::istream & operator >> (std::istream &is, text &t);
    std::ostream & operator << (std::ostream &os, const text &t);
}

#endif