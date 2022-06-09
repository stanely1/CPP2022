#include "svg.hpp"

using namespace svg_document;

document_root::document_root() : xml_document::element("svg") {}

rectangle::rectangle(const std::vector<std::pair<std::string,std::string>> &_attrs) : xml_document::element("rect")
{
    for(auto a : _attrs) add_attribute(xml_document::attribute(a.first,a.second));
}
ellipse::ellipse(const std::vector<std::pair<std::string,std::string>> &_attrs) : xml_document::element("ellipse")
{
    for(auto a : _attrs) add_attribute(xml_document::attribute(a.first,a.second));
}
circle::circle(const std::vector<std::pair<std::string,std::string>> &_attrs) : xml_document::element("circle")
{
    for(auto a : _attrs) add_attribute(xml_document::attribute(a.first,a.second));
}
line::line(const std::vector<std::pair<std::string,std::string>> &_attrs) : xml_document::element("line")
{
    for(auto a : _attrs) add_attribute(xml_document::attribute(a.first,a.second));
}
polygon::polygon(const std::vector<std::pair<std::string,std::string>> &_attrs) : xml_document::element("polygon")
{
    for(auto a : _attrs) add_attribute(xml_document::attribute(a.first,a.second));
}