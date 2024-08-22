#include <vector>

struct DSU {
   std::vector<int> p;
   std::vector<int> s;
   int sz;

    DSU(int n) :sz(n) {
        p.resize(n); s.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i; s[i] = 1;
        }
    }

    int size(int x) {
        int root = find(x);
        return s[root];
    }

    int find(int x) {
        int y = x;
        while (p[y] != y) y = p[y];
        while (p[x] != x) {
            int z = p[x];
            p[x] = y;
            x = z;
            }
        return y;
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (s[x] > s[y]) std::swap(x, y);
        p[x] = y;
        s[y] += s[x];
    }
};