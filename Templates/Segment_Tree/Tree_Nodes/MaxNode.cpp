#include <bits/stdc++.h>
using namespace std;

// Max node for seg tree
template <typename T>
struct MaxNode {
    T val;
    MaxNode() : val(std::numeric_limits<T>::min()) {}
    MaxNode(const T &v) : val(v) {}

    static MaxNode merge(const MaxNode &a, const MaxNode &b) {
        MaxNode res;
        res.val = std::max(a.val, b.val);
        return res;
    }
};
// template <typename T> using Segtree = SegtreeImpl<MaxNode<T>>;

template <typename T> string to_string(const MaxNode<T> &info) { return "{ max=" + to_string(info.val) + " }"; }
