#include "bst.hpp"

using namespace std;

int main()
{
    bst<int> t;
    t.insert(3);
    t.insert(1);
    t.insert(2);

    bst<int,decreasing_order<int>> w {3,2,4,1};
    bst<int,decreasing_order<int>> u = w;
    bst<string,decreasing_order<string>> s {"a", "ab", "abc"};
    s.insert("babcia");
    s.remove("a");
    cout << t << w.size() << ", " << w << u.size() << ", " << u << s.size() << ", " << s;
    bst<int> v{5,6,7,8,9};

    cout << v.size() << ", " << v;
    v = t;
    cout << v.size() << ", " << v << "\n";

    t = bst<int>();
    while(true)
    {
        string op;
        cin >> op;
        if(op == "insert")
        {
            int x; cin >> x;
            t.insert(x);
        }
        else if(op == "remove")
        {
            int x; cin >> x;
            try {
                t.remove(x);
            } catch(invalid_argument &e) {
                cerr << e.what() << "\n";
            }
        }
        else if(op == "find")
        {
            int x; cin >> x;
            cout << boolalpha << t.find(x) << "\n";
        }
        else if(op == "print") cout << t;
        else if(op == "size") cout << t.size() << "\n";
        else if(op == "exit") break;
        else cerr << "invalid input\n";

    }
}