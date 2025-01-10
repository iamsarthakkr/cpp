#include<bits/stdc++.h>
using namespace std;

// Sum node for seg tree
template<typename T> class SumNode {
public:
    SumNode() {}
    template<typename U> SumNode(U v) : sum(v) {}
public:
    static SumNode merge(const SumNode& a, const SumNode& b) {
        SumNode res;
        res.sum = a.sum + b.sum;
        return res;
    }
public:
    T sum = 0;
};
template<typename T> using Segtree = SegtreeImpl<SumNode<T>>;

string to_string(const SumNode<int>& node) { return "{ " + to_string(node.sum) + " }"; }