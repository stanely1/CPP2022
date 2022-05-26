#ifndef BST_TPP
#define BST_TPP

#include "bst.hpp"

// traits
template<class T>
bool increasing_order<T>::operator () (T a, T b)
{
    return a < b;
}
template<class T>
bool increasing_order<T*>::operator () (T *a, T *b)
{
    return *a < *b;
}
template<>
bool increasing_order<const char*>::operator () (const char *a, const char *b)
{
    return std::string(a) < std::string(b);
}

template<class T>
bool decreasing_order<T>::operator () (T a, T b)
{
    return a > b;
}
template<class T>
bool decreasing_order<T*>::operator () (T *a, T *b)
{
    return *a > *b;
}
template<>
bool decreasing_order<const char*>::operator () (const char *a, const char *b)
{
    return std::string(a) > std::string(b);
}

// node
template<class T, class C>
bst<T,C>::node::node(T _val) : val(_val) {}

template<class T, class C>
bst<T,C>::node::~node()
{
    delete left;
    delete right;
}

// bst
// konstruktory
template<class T, class C>
bst<T,C>::bst(std::initializer_list<T> l)
{
    for(auto i : l) insert(i);
}
template<class T, class C>
bst<T,C>::bst(const bst &t) // konstruktor kopiujacy 
{
    *this = t;
}
template<class T, class C>
bst<T,C>::bst(bst &&t) : _size(t._size), root(t.root) // konstruktor przenoszacy 
{
    t._size = 0;
    t.root = nullptr;
}

template<class T, class C>
bst<T,C>::~bst() // destruktor
{
    delete root;
    _size = 0;
    root = nullptr;
}

// przypisania
template<class T, class C>
bst<T,C> & bst<T,C>::operator = (const bst &t) // kopiujace
{
    if(this != &t)
    {
        this->~bst();
        root = nullptr;
        _size = 0;
        //t.iterate([&](const T &x){insert(x);},t.root);
        iterate_copy(t.root);
    }
    return *this;
}

template<class T, class C>
bst<T,C> & bst<T,C>::operator = (bst &&t) // przenoszace
{
    if(this != &t)
    {
        this->~bst();
        _size = t._size;
        root = t.root;
        
        t._size = 0;
        t.root = nullptr;
    }
    return *this;
}

// iteracja
// template<class T, class C>
// template<class F>
// void bst<T,C>::iterate(F &f, node *t)
// {
//     if(t == nullptr) return;

//     iterate(f,t->left);
//     f(t->val);
//     iterate(f,t->right);
// }

template<class T, class C>
void bst<T,C>::iterate_copy(bst<T,C>::node *t)
{
    if(t == nullptr) return;
    insert(t->val);
    iterate_copy(t->left);
    iterate_copy(t->right);
}

// print - specjalizacja
template<class T>
struct print_aux {
    static void print_elem(std::ostream &os, T &x) {os << x << " ";}
};
template<class T>
struct print_aux<T*> {
    static void print_elem(std::ostream &os, T *x) {os << *x << " ";}
};
template<>
struct print_aux<const char*> {
    static void print_elem(std::ostream &os, const char *x) {os << x << " ";}
};

template<class T, class C>
void bst<T,C>::iterate_print(std::ostream &os, bst<T,C>::node *t) const
{
    if(t == nullptr) return;
    iterate_print(os,t->left);
    //os << t->val << " ";
    print_aux<T>::print_elem(os, t->val); // trikowe rozwiazanie
    iterate_print(os,t->right);
}

// operacje
template<class T, class C>
void bst<T,C>::insert(T x)
{
    _size++;
    if(root == nullptr)
    {
        root = new node(x);
        return;
    }

    node *curr = root;
    while(curr != nullptr)
    {
        if(cmp(curr->val,x)) // curr->val < x -> w prawo
            if(curr->right == nullptr)
            {
                curr->right = new node(x);
                break;
            }
            else curr = curr->right;
        else if(cmp(x,curr->val)) // x < curr->val -> w lewo
            if(curr->left == nullptr)
            {
                curr->left = new node(x);
                break;
            }
            else curr = curr->left;
        else {_size--; break;} // juz jest w drzewie
    }
}
template<class T, class C>
void bst<T,C>::remove(T x) /// ? trzeba uzyc node ** (?) (w insert tez?)
{
    node *curr = root;
    node *prev = nullptr;
    bool dir = false;

    while(curr)
    {
        if(cmp(curr->val,x)) 
            dir = 1, prev = curr, curr = curr->right;
        else if(cmp(x,curr->val))
            dir = 0, prev = curr, curr = curr->left;
        else break;
    }

    if(curr == nullptr) throw std::invalid_argument("remove: brak elementu w drzewie");

    _size--;

    if(prev == nullptr) // usuniecie roota
        if(curr->right) root = curr->right;
        else {root = curr->left; return;}
    else if(curr->right)
        dir ? prev->right = curr->right : prev->left = curr->right;
    else
    {
        dir ? prev->right = curr->left : prev->left = curr->left;
        return;
    }

    node *clft = curr->left;
    curr = curr->right;
    while(curr->left) curr = curr->left;
    curr->left = clft;
}
template<class T, class C>
bool bst<T,C>::find(T x)
{
    node *curr = root;
    while(curr != nullptr)
    {
        if(cmp(curr->val,x)) curr = curr->right;
        else if(cmp(x,curr->val)) curr = curr->left;
        else return true;
    }
    return false;
}

template<class T, class C>
size_t bst<T,C>::size() {return _size;}

// stream operator
template<class T, class C>
std::ostream & operator << (std::ostream &os, const bst<T,C> &t)
{
    // t.iterate([&](const T &x){std::cout << x << ' ';},t.root);
    t.iterate_print(os,t.root);
    return os << '\n';
}

#endif