#include<bits/stdc++.h>

struct SegmentTree {
	struct node {
		// make sure to change the default values for different cases (initial value of the node)
		long long min = 0LL;	// default values
		long long add = NO_OP;
		static const long long NO_OP = -1LL;

		void apply(int l, int r, long long v) {
			if (v == NO_OP) return;
			min += v;
			add == NO_OP ? add = v : add += v;
		}
	};

	// Item corresponding to empty set such that merge(NEUTRAL_ELEMENT, node) = node i.e. merging some node with the neutral element doesn't change the node
	const node NEUTRAL_ELEMENT = { __LONG_LONG_MAX__, node::NO_OP };
	// node item corresponding to leaves
	node single(long long v) {
		return { v, node::NO_OP };
	}
	// merge 2 child nodes to get the value of parent
	node merge(const node& a, const node& b) {
		node res;
		res.min = std::min(a.min, b.min);
		return res;
	}

	// lazy prop
	void prop(int x, int lx, int rx) {
		if (rx - lx == 1) return;
		int m = (lx + rx) / 2;
		tree[2 * x + 1].apply(lx, m, tree[x].add); tree[2 * x + 2].apply(m, rx, tree[x].add);
		tree[x].add = node::NO_OP;
	}

	/* Nothing  below should change */

	/* Operations on the Segment Tree */
	template<typename... T>
	void set(int x, int lx, int rx, int i, T... v) {
		if (rx - lx == 1) {
			tree[x] = single(v...); return;
		}
		int m = (lx + rx) / 2;
		i < m ? set(2 * x + 1, lx, m, i, v...) : set(2 * x + 2, m, rx, i, v...);
		tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
	}

	template<typename... T>
	void set(int i, T... v) {
		assert(i >= 0 && i < size);
		set(0, 0, size, i, v...);
	}

	node get(int x, int lx, int rx, int l, int r) {
		if (r <= lx || rx <= l) return NEUTRAL_ELEMENT; // disjoint range
		if (l <= lx && r >= rx) return tree[x]; // complete covering

		prop(x, lx, rx);
		int m = (lx + rx) / 2;
		return merge(get(2 * x + 1, lx, m, l, r), get(2 * x + 2, m, rx, l, r));
	}

	node get(int i) {
		assert(i >= 0 && i < size);
		return get(0, 0, size, i, i + 1);
	}

	node get(int l, int r) {
		assert(l >= 0 && l < r&& r <= size);
		return get(0, 0, size, l, r);
	}

	template<typename... T>
	void modify(int x, int lx, int rx, int l, int r, T... v) {
		if (r <= lx || rx <= l) return; // disjoint range
		if (l <= lx && r >= rx) return tree[x].apply(lx, rx, v...); // complete covering

		prop(x, lx, rx);
		int m = (lx + rx) / 2;
		modify(2 * x + 1, lx, m, l, r, v...); modify(2 * x + 2, m, rx, l, r, v...);
		tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
	}

	template<typename... T>
	void modify(int l, int r, T... v) {
		assert(l >= 0 && l < r&& r <= size);
		modify(0, 0, size, l, r, v...);
	}

	/* Building Functions */
	void build(int x, int lx, int rx) {
		if (rx - lx == 1) {
			return; // default values
		}
		int m = (rx + lx) / 2;
		build(2 * x + 1, lx, m); build(2 * x + 2, m, rx);
		tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
	}

	template<typename T>
	void build(int x, int lx, int rx, const std::vector<T>& a) {
		if (rx - lx == 1) {
			tree[x] = lx < (int)a.size() ? single(a[lx]) : NEUTRAL_ELEMENT; return;
		}
		int m = (rx + lx) / 2;
		build(2 * x + 1, lx, m, a); build(2 * x + 2, m, rx, a);
		tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
	}

	/* Constructors */
	SegmentTree(int n) {
		size = 1; while (size < n) size *= 2;
		tree.resize(2 * size); build(0, 0, size);
	}

	template<typename T>
	SegmentTree(const std::vector<T>& a) {
		size = 1; while (size < (int)a.size()) size *= 2;
		tree.resize(2 * size); build(0, 0, size, a);
	}

	std::vector<node> tree;
	int size;
};