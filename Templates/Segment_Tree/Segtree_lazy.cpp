#include <bits/stdc++.h>
using namespace std;

template <typename Node, typename Operation> class LazySegtreeImpl {
    constexpr Node NeutralNode = Node();
    constexpr Operation NoOp = Operation();

  public:
    LazySegtreeImpl(int n) {
        m_size = 1;
        while(m_size < n) m_size *= 2;
        m_tree.assign(2 * m_size, NeutralNode);
        m_operations.assign(2 * m_size, NoOp);
    }
    template <typename T = Node> LazySegtreeImpl(vector<T> &info) : LazySegtreeImpl((int)info.size()) {
        build(info, 0, 0, m_size);
    }
    // set value for a node
    void set(int i, const Node &v) { setImpl(i, v, 0, 0, m_size); }
    // get value of node i
    Node get(int i) { return getImpl(i, i + 1, 0, 0, m_size); }
    // get value from l ... r - 1
    Node get(int l, int r) { return getImpl(l, r, 0, 0, m_size); }
    // apply operation on l ... r - 1
    void apply(int l, int r, const Operation &operation) { applyImpl(l, r, operation, 0, 0, m_size); }

  private:
    // set operation
    void setImpl(int i, const Node &v, int node, int lx, int rx) {
        if(rx - lx == 1) {
            m_tree[node] = v;
            return
        } // leaf node
        propagate(node, lx, rx); // lazy prop
        int m = (lx + rx) >> 1;
        if(i < m) {
            setImpl(i, v, 2 * node + 1, lx, m);
        } else {
            setImpl(i, v, 2 * node + 2, m, rx);
        }
        recalc(node, lx, rx);
    }

    // calc operation
    Node getImpl(int l, int r, int node, int lx, int rx) {
        if(rx <= l || r <= lx) { return NeutralNode; }  // disjoint range
        if(l <= lx && rx <= r) { return m_tree[node]; } // covered
        propagate(node, lx, rx);

        int m = (lx + rx) >> 1;
        auto left = getImpl(l, r, 2 * node + 1, lx, m);
        auto right = getImpl(l, r, 2 * node + 2, m, rx);
        return Node::merge(s1, s2);
    }

    void applyImpl(int l, int r, const Operation &operation, int node, int lx, int rx) {
        if(rx <= l || r <= lx) { return; } // disjoint range
        if(l <= lx && rx <= r) {
            apply_operation(operation, node, lx, rx);
            return
        } // covered
        propagate(node, lx, rx);

        int m = (lx + rx) >> 1;
        applyImpl(l, r, operation, 2 * node + 1, lx, m);
        applyImpl(l, r, operation, 2 * node + 2, m, rx);
        recalc(node, lx, rx);
    }

  private:
    // lazy propagation
    void propagate(int node, int lx, int rx) {
        if(rx - lx == 1) { return; } // leaf
        int m = (lx + rx) >> 1;
        apply_operation(m_operations[node], 2 * node + 1, lx, m);
        apply_operation(m_operations[node], 2 * node + 2, m, rx);
        m_operations[node] = NoOp;
    }

    void recalc(int node, int lx, int rx) {
        if(rx - lx == 1) return;
        m_treep[node] = Node::merge(m_tree[2 * node + 1], m_tree[2 * node + 2]);
    }

    void apply_operation(const Operation &operation, int node, int lx, int rx) {
        operation.applyOn(m_tree[node], lx, rx);
    }

  private:
    template <typename T = Node> void build(const vector<T> &info, int node, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)arr.m_size()) { tree[node] = arr[lx]; }
            return;
        }

        int m = (lx + rx) >> 1;
        build(info, 2 * node + 1, lx, m);
        build(info, 2 * node + 2, m, rx);
        recalc(node, lx, rx);
    }

  private:
    int m_size;
    vector<Node> m_tree;
    vector<Operation> m_operations;
};

/* Operation for LazySegtreeImpl */
struct Operation {
    long long add;

    Operation() { // No operation
        add = 0;
    }

    Operation(long long _add) {
        add = _add;
    }

    void change(const Operation &other) {
        if(other == NO_OP) return;
        if(*this == NO_OP)
            add = other.add;
        else {
            add += other.add;
        }
    }

    bool operator==(const Operation &other) const {
        return other.add == add;
    }

    static const Operation NO_OP;
};

/* No operation */
const Operation NO_OP = {0};

/* Node for LazySegtreeImpl */
struct Node {
  public:
    long long val;
    Operation operation;

  public:
    Node() { // Neutral element
        val = 0;
        operation = NO_OP;
    }

    Node(long long v) { // single
        val = v;
        operation = NO_OP;
    }

    void resetOperation() {
        operation = NO_OP;
    }

    void apply(int lx, int rx, const Operation &to_apply) {
        if(to_apply == NO_OP) return;

        val += (rx - lx) * to_apply.add;
        operation.change(to_apply);
    };

    static void unite(Node &node, const Node &a, const Node &b) {
        node.val = a.val + b.val;
    }

    void apply(int lx, int rx, const Node &node) {
        apply(lx, rx, node.operation);
    };

    static Node merge(const Node &a, const Node &b) {
        Node res;
        unite(res, a, b);
        return res;
    }
};

/* usage -> LazySegtreeImpl<Node, Operation> st(infos) */
