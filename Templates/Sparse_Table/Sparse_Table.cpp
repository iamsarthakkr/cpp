#include <bits/stdc++.h>

// For range min
template<typename T>
class Sparse_Table {
public:
	Sparse_Table(const std::vector<T>& arr) {
		size = arr.size();
		LOG = 1;
		while((1 << LOG) < size) LOG++;
		m.assign(LOG + 1, std::vector<T> (size));
		log.assign(size + 1, 0);

		init(arr);
	}

	T get(int l, int r) {
		r++;
		int len = r - l;

		int lg = log[len];
		return std::min(m[lg][l], m[lg][r - (1 << lg)]);
	}

private:
	void init(const std::vector<T>& arr) {
		int n = arr.size();
		for(int jump = 0; jump <= LOG; jump++) {
			for(int i = 0; i < n; i++) {
				if(jump == 0) {
					m[jump][i] = arr[i];
					continue;
				}
				int mid = i + (1 << (jump - 1));
				m[jump][i] = std::min(m[jump - 1][i], mid < n ? m[jump - 1][mid] : __LONG_LONG_MAX__);
			}
		}

		for(int i = 0; i <= n; i++) {
			int lg = 0;
			while((1 << (lg + 1)) < i) lg++;
			log[i] = lg;
		}
	}

private:
	std::vector<std::vector<T>> m;
	std::vector<int> log;
	int size;
	int LOG;
};