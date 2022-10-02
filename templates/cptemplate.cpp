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


void Main() {

}


int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cout << setprecision(12) << fixed;
#ifdef SARTHAK_LOCAL
   freopen("./input.txt", "r", stdin); freopen("./output.txt", "w", stdout);
#endif

	int tt = 1;
	if (MULTI) cin >> tt;

	for(int test_case = 1; test_case <= tt; test_case++) {
		debug(test_case);
		Main();
	}

#ifdef SARTHAK_LOCAL
   cerr << "Total Time: " << clock() / CLOCKS_PER_SEC << "s" << '\n';
#endif
   return 0;
}