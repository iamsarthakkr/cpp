#include<bits/stdc++.h>
using namespace std;

// Min node for seg tree
template<typename T, T max_element = numeric_limits<T>::max()> class Min_Node {
public:
    Min_Node() {}
    template<typename U> Min_Node(U v) : min(v) {}
public:
    static Min_Node merge(const Min_Node& a, const Min_Node& b) {
        Min_Node res;
        res.min = std::min(a.min, b.min);
        return res;
    }
public:
    T min = max_element;
};
template<typename T, T max_element = numeric_limits<T>::max()>
using Segtree = SegtreeImpl<Min_Node<T, max_element>>;

string to_string(const Min_Node<int>& info) { return "{ " + to_string(info.min) + " }"; }