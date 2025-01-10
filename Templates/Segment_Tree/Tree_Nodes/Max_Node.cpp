#include<bits/stdc++.h>
using namespace std;

// Min node for seg tree
template<typename T> class Max_Node {
public:
    Max_Node() {}
    template<typename U> Max_Node(U v) : max(v) {}
public:
    static Max_Node merge(const Max_Node& a, const Max_Node& b);
public:
    T max = numeric_limits<T>::min();
};

string to_string(const Max_Node<int>& info) { return "{ " + to_string(info.max) + " }"; }

template<typename T> Max_Node<T> Max_Node<T>::merge(const Max_Node<T>& a, const Max_Node<T>& b) {
    Max_Node res;
    res.min = std::min(a.min, b.min);
    return res;
} 

template<typename T> using Segtree = SegtreeImpl<Max_Node<T>>;