#ifndef BST_HPP
#define BST_HPP

#include <iostream>
// #include <functional>

// traits
template<class T>
class increasing_order {
public:
    bool operator () (T a, T b);
};
template <class T>
class increasing_order<T*> {
public:
    bool operator () (T *a, T *b);
};

template<class T>
class decreasing_order {
public:
    bool operator () (T a, T b);
};
template<class T>
class decreasing_order<T*> {
public:
    bool operator () (T *a, T *b);
};

// main class
template<class T, class C = increasing_order<T>>
class bst {
private:
    class node {
    public:
        T val;
        node *left = nullptr, *right = nullptr;

        node(T _val);
        ~node();
    };

    size_t _size = 0;
    node *root = nullptr;
    C cmp;

    // template<class F>
    // void iterate(F &f, node *t);

    void iterate_copy(node *t);
    void iterate_print(std::ostream &os, node *t) const;
public:
    bst() = default;
    bst(std::initializer_list<T> l);
    bst(const bst &t);  // kopiujacy
    bst(bst &&t);       // przenoszacy

    ~bst();

    bst & operator = (const bst &t);
    bst & operator = (bst &&t);

    void insert(T x);
    void remove(T x);
    bool find(T x);

    size_t size();
    //friend std::istream & operator >> (std::istream &is, bst &t);
    template <class osT, class osC>
    friend std::ostream & operator << (std::ostream &os, const bst<osT,osC> &t);

    //size_t size();
};
template<class T, class C>
std::ostream & operator << (std::ostream &os, const bst<T,C> &t);

#include "bst.tpp"

#endif