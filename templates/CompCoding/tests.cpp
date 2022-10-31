#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/cpp/templates/debug.cpp"
#else 
#define debug(...) 69
#endif

template<typename T> bool cmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool cmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(696969);

#define MULTI 1	// 0 for single test case


#define MULTI 1	// 0 for single test case
namespace Random {
	std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

	long long nextLongLong() {
		return rng();
	}

	long long nextLongLong(long long x) {
		return std::uniform_int_distribution<long long>(0, x)(rng);
	}

	long long nextLongLong(long long a, long long b) {
		return std::uniform_int_distribution<long long>(a, b)(rng);
	}

	int nextInt() {
		return (int)nextLongLong()%INT32_MAX;
	}

	int nextInt(int x) {
		return (int)nextLongLong(x);
	}

	int nextInt(int a, int b) {
		return (int)nextLongLong(a, b);
	}

	bool nextBoolean() {
		return nextInt(1);
	}

	std::vector<int> nextVector(int n, int mx = INT32_MAX) {
		std::vector<int> a(n);
		for (int& x : a) x = nextInt(mx);
		return a;
	}

	std::vector<long long> nextVector(int n, long long mx = INT64_MAX) {
		std::vector<long long> a(n);
		for (long long& x : a) x = nextLongLong(mx);
		return a;
	}
}
using namespace Random;



#include "./Segment_Tree_basic.cpp"


int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cout << setprecision(12) << fixed;
#ifdef SARTHAK_LOCAL
   // freopen("./output.txt", "w", stdout);
#endif

   int n = 1000;
   vector<long long> a(n);
   for(int i = 0; i < n; i++) a[i] = nextInt(100000);

   debug(n, a);
   cout << a[n + 1];
   segtree st(0, n, a);
   
   for(int q = 0; q < 10000; q++) {
      if(nextBoolean()) {
         ll v = nextInt(100000), i = nextInt(n - 1);
         a[i] = v;
         st.update(i, v);
      } else {
         int l = nextInt(0, n - 1), r = nextInt(0, n - 1);
         if(l > r) swap(l, r);

         ll s = 0;
         for(int i = l; i <= r; i++) s += a[i];
         assert(st.calc(l, r + 1) == s);
      }
   }

   cout << "PASSED\n";
	

#ifdef SARTHAK_LOCAL
   cerr << "Total Time: " << clock() / CLOCKS_PER_SEC << "s" << '\n';
#endif
   return 0;
}