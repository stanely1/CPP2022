#ifndef SVG_HPP
#define SVG_HPP

#include "xml.hpp"

namespace svg_document {
    class document_root : public xml_document::element {
    public:
        document_root();
    };

    class rectangle : public xml_document::element {
    public:
        rectangle(const std::vector<std::pair<std::string,std::string>> &_attrs);
    };

    class line : public xml_document::element {
    public:
        line(const std::vector<std::pair<std::string,std::string>> &_attrs);
    };

    class circle : public xml_document::element {
    public:
        circle(const std::vector<std::pair<std::string,std::string>> &_attrs);    
    };

    class ellipse : public xml_document::element {
    public:
        ellipse(const std::vector<std::pair<std::string,std::string>> &_attrs);
    };

    class polygon : public xml_document::element {
    public:
        polygon(const std::vector<std::pair<std::string,std::string>> &attrs);
    };
}

#endif