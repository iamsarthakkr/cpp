#include <vector>
struct DSU {
	std::vector<int> p;
	std::vector<int> size;
	int sz;

	DSU(int n) :sz(n) {
		p.resize(n + 1); size.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			p[i] = i; size[i] = 1;
		}
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
		if (size[x] > size[y]) std::swap(x, y);
		p[x] = y;
		size[y] += size[x];
	}
};
