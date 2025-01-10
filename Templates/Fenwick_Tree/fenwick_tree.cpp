#include<bits/stdc++.h>
using namespace std;

template<typename T> class Fenwick {
public:
	Fenwick(int n, T v = static_cast<T>(0)) { m_fenwick.assign(n, v); }
    template<typename U> Fenwick(const vector<U>& a) { m_fenwick.assign(a.begin(), a.end()); }

    // Update node i with value v
	void update(int i, T v) {
		int j = i;
		while(j < (int)m_fenwick.size()) {
			m_fenwick[j] += v;
			j = j | (j + 1);
		}
	}
    // Get sum from l ... r
	T get(int l, int r) { return pref(r) - pref(l - 1); }
private:
	T pref(int r) {
		int i = r;
		T res = 0;
		while (i >= 0) {
			res += m_fenwick[i];
			i = (i & (i + 1)) - 1;
		}
		return res;
	}

private:
	std::vector<T> m_fenwick;
};