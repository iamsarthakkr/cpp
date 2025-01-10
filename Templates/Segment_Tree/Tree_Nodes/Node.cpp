#include<bits/stdc++.h>
using namespace std;

template<typename Node> class SegtreeImpl {
public:
    // Initialize with empty values
    SegtreeImpl(int n) { m_size = 1; while(m_size < n) m_size *= 2; m_tree.assign(2 * m_size, Node()); }
    // initialize with list of values
    template<typename T = Node> SegtreeImpl(vector<T>& info) : SegtreeImpl((int)info.size()) { build<T>(info, 0, 0, m_size); }
    // set value for a node
    void set(int i, const Node& v) { setImpl(i, v, 0, 0, m_size); }
    // get value of node i
    Node get(int i) { return getImpl(i, i + 1, 0, 0, m_size); }
    // get result for range l ... r - 1
    Node get(int l, int r) { return getImpl(l, r, 0, 0, m_size); }

private:
    // set implementation
    void setImpl(int i, const Node& v, int node, int lx, int rx) {
        if(rx - lx == 1) { m_tree[node] = v; return; } // leaf node
        int m = (lx + rx) >> 1;
        if(i < m) { setImpl(i, v, 2 * node + 1, lx, m); }
        else      { setImpl(i, v, 2 * node + 2, m, rx); }
        recalc(node, lx, rx);
    }
    // calc operation
    Node getImpl(int l, int r, int node, int lx, int rx) {
        if(rx <= l || r <= lx) { return Node(); } // neutral element
        if(l <= lx && rx <= r) { return m_tree[node]; } // covered

        int m = (lx + rx) >> 1;
        auto left = getImpl(l, r, 2 * node + 1, lx, m);
        auto right = getImpl(l, r, 2 * node + 2, m, rx);
        return Node::merge(left, right);
    }
private:
    template<typename T = Node> void build(const vector<T>& info, int node, int lx, int rx) {
        if(rx - lx == 1) { // leaf node
            if(lx < (int) info.size()) { 
                m_tree[node] = info[lx]; 
            }
            return;
        }
        int m = (lx + rx) >> 1; build(info, 2 * node + 1, lx, m); build(info, 2 * node + 2, m, rx); recalc(node, lx, rx);
    }
private:
    // recalculate value for a node
    void recalc(int node, int lx, int rx) {
        if(rx - lx == 1) { return; } // leaf node
        m_tree[node] = Node::merge(m_tree[2 * node + 1], m_tree[2 * node + 2]);
    }
private:
    int m_size;
    vector<Node> m_tree;
};

// Node for segtree
class Node {
public:
    Node() {}
    Node(int v) : value(v) {}
public:
    // Merge values for child nodes
    static Node merge(const Node& a, const Node& b) {
        Node res;
        
        return res;
    }
public:
    // Make sure to set default values here
    int value;
};
// string to_string(const Node& info) { return "{ " + to_string(info.value) + " }"; }

using Segtree = SegtreeImpl<Node>;
