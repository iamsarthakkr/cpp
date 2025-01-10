#include<bits/stdc++.h>
using namespace std;

// Max node for seg tree
template<typename T, T min_element = numeric_limits<T>::min()> class Max_Node {
public:
    Max_Node() {}
    template<typename U> Max_Node(U v) : max(v) {}
public:
    static Max_Node merge(const Max_Node& a, const Max_Node& b) {
        Max_Node res;
        res.min = std::min(a.min, b.min);
        return res;
    }
public:
    T max = min_element;
};
template<typename T> using Segtree = SegtreeImpl<Max_Node<T>>;

string to_string(const Max_Node<int>& info) { return "{ " + to_string(info.max) + " }"; }

