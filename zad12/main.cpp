#include "ios_manipulators.hpp"
#include "xml.hpp"
#include "svg.hpp"

using namespace std;
using namespace xml_document;
using namespace svg_document;

int main()
{
    string s, w;

    cin >> clearline >> s >> w;
    // cin >> s >> clearline >> w;
    cout << s << " " << w << "\n";

    cin >> ignore(5) >> s;
    cout << s << "\n";

    cout << quot << amp << lt << gt << quot << "\n";
    cout << attr("bajo","jajo") << "\n\n";

    element root("root");
    root.add_attribute(attribute("a1","v1"));
    root.add_attribute(attribute("a2","v2"));
    root.add_content(content(new element("child1")));
    root.add_content(content(new text("text1")));

    element child2("child2");
    child2.add_attribute(attribute("a3","v3"));
    child2.add_content(content(new text("text2")));
    root.add_content(content(&child2));

    document d(root);
    cout << d << "\n";

    // element r2;
    // document d2(r2);
    // cin >> d2;
    // cout << d2 << "\n";

    rectangle rect({{"width","400"},{"height","200"},
                    {"style","fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,0)"}});
    circle circ({{"cx","150"},{"cy","200"},{"r","76"},{"fill","red"}});
    
    document_root image;
    image.add_content(&rect);
    image.add_content(&circ);
    image.add_attribute("width","500");
    image.add_attribute("height","500");

    document svgimage(image);
    cout << svgimage << "\n";
}