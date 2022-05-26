#include "bst.hpp"
using namespace std;

int main()
{
    int x[5] = {5, 2, 1, 4, 3};
    bst<int*> t;
    bst<int*,decreasing_order<int*>> u;

    for(int i = 0; i < 5; i++)
        t.insert(x+i), u.insert(x+i);
    cout << t << u;

    bst<const char*> w {"jacek", "babcia", "ala", "bartek"};
    bst<const char*,decreasing_order<const char*>> v {"jacek", "babcia", "ala", "bartek"};
    cout << w << v;
}