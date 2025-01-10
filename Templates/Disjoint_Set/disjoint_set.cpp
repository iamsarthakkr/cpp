#include<bits/stdc++.h>
using namespace std;

class disjoint_set {
   vector<int> parent;
   vector<int> size;

    disjoint_set(int n) {
        parent.resize(n); size.resize(n);
        for (int i = 0; i < n; i++) { parent[i] = i; size[i] = 1; }
    }

    int get_size(int x) { int root = find(x); return size[root]; }
    
    int find(int x) {
        int y = x;
        while (parent[y] != y) y = parent[y];
        while (parent[x] != x) {
            int z = parent[x];
            parent[x] = y;
            x = z;
        }
        return y;
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] > size[y]) swap(x, y);
        parent[x] = y; size[y] += size[x];
    }
};