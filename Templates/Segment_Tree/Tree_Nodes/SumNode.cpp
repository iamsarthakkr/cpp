#include <bits/stdc++.h>
using namespace std;

// Sum node for seg tree
template <typename T>
struct SumNode {
    T val;
    SumNode() : val(T(0)) {}
    SumNode(const T &v) : val(v) {}

    static SumNode merge(const SumNode &a, const SumNode &b) {
        SumNode res;
        res.val = a.val + b.val;
        return res;
    }
};
template <typename T> string to_string(const SumNode<T> &node) { return "{ sum= " + to_string(node.val) + " }"; }

// template <typename T> using Segtree = SegtreeImpl<SumNode<T>>;
