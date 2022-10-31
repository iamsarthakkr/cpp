#include<bits/stdc++.h>

class Fenwick {
public:
	Fenwick(int n) {
		size = n;
		fenwick.assign(n, 0);
	}

	void update(int i, long long v) {
		int j = i;
		while(j < size) {
			fenwick[j] += v;
			j = j | (j + 1);
		}
	}


	long long get(int l, int r) {
		return pref(r) - pref(l - 1);
	}

private:
	long long pref(int r) {
		int i = r;
		long long res = 0;
		while (i >= 0) {
			res += fenwick[i];
			i = (i & (i + 1)) - 1;
		}
		return res;
	}

private:
	std::vector<long long> fenwick;
	int size;
};