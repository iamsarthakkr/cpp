#include<bits/stdc++.h>
using namespace std;

// Sum node for seg tree
template<typename T> class SumNode {
public:
    SumNode() {}
    template<typename U> SumNode(U v) { // Neutral element
        sum = v;
    }
public:
    static SumNode merge(const SumNode& a, const SumNode& b);
public:
    // NOTE: Initialize with neutral values
    T sum = 0;
};

string to_string(const SumNode<int>& node) { return "{ " + to_string(node.sum) + " }"; }

template<typename T> SumNode<T> SumNode<T>::merge(const SumNode<T>& a, const SumNode<T>& b) {
    SumNode res;
    res.sum = a.sum + b.sum;
    return res;
} 

template<typename T> using Segtree = SegtreeImpl<SumNode<T>>;