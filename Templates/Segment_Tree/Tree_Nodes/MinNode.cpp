#include <bits/stdc++.h>
using namespace std;

// Min node for seg tree
template <typename T>
struct MinNode {
    T val;
    MinNode() : val(std::numeric_limits<T>::max()) {}
    MinNode(const T &v) : val(v) {}

    static MinNode merge(const MinNode &a, const MinNode &b) {
        MinNode res;
        res.val = std::min(a.val, b.val);
        return res;
    }
};
// template <typename T> using Segtree = SegtreeImpl<MinNode<T>>;

template <typename T> string to_string(const MinNode<T> &info) { return "{ min=" + to_string(info.val) + " }"; }
