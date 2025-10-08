#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct MinCountNode {
    T mn;
    int cnt;
    MinCountNode() : mn(std::numeric_limits<T>::max()), cnt(0) {}
    MinCountNode(T v, int c = 1) : mn(v), cnt(c) {}

    static MinCountNode merge(const MinCountNode &a, const MinCountNode &b) {
        if(a.mn < b.mn) return a;
        if(b.mn < a.mn) return b;
        return {a.mn, a.cnt + b.cnt};
    }
};

// template <typename T> using Segtree = SegtreeImpl<MinCountNode<T>>;

template <typename T> string to_string(const MinCountNode<T> &info) { return "{ min=" + to_string(info.mn) + ", cnt=" + to_string(info.cnt) + " }"; }
