#include<bits/stdc++.h>
using namespace std;

// Min node for seg tree
template<typename T> class Min_Node {
public:
    Min_Node() {}
    template<typename U> Min_Node(U v) { // Neutral element
        min = v;
    }
public:
    static Min_Node merge(const Min_Node& a, const Min_Node& b);
public:
    // NOTE: Initialize with neutral values
    T min = numeric_limits<T>::max();
};

string to_string(const Min_Node<int>& info) { return "{ " + to_string(info.min) + " }"; }

template<typename T> Min_Node<T> Min_Node<T>::merge(const Min_Node<T>& a, const Min_Node<T>& b) {
    Min_Node res;
    res.min = std::min(a.min, b.min);
    return res;
} 

template<typename T> using Segtree = SegtreeImpl<Min_Node<T>>;