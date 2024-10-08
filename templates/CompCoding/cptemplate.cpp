#include <bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
*/

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < n; i++)
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define forr(i, l, r) for(int i = l; i <= r; i++)
#define forrd(i, l, r) for(int i = r; i >= l; i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(a) (int)(a).size()
#define sq(x) (x) * (x)

void timeIt() {
	#ifdef SARTHAK_LOCAL
		cerr << "Total Time: " << (double)clock() * 1e3 / CLOCKS_PER_SEC << "ms" << '\n';
	#endif
}

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/cpp/templates/CompCoding/debug.cpp"
#else 
#define debug(...) 69
#endif

template<typename T> bool cmin(T& a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool cmax(T& a, T b) { return b > a ? a = b, 1 : 0; }

template<typename T>
T gcd(T a, T b) {
	while (b) { a %= b; swap(a, b); }
	return a;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(696969);

void Main() {

}

#define MULTI	// comment for single test

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL); cout << setprecision(12) << fixed;
	int tt = 1;
	#ifdef MULTI 
		cin >> tt;
	#endif

    for(int t = 1; t <= tt; t++) {
        #ifdef SARTHAK_LOCAL
            cerr << "Test Case: #" << t << '\n';
            cerr << "---------------" << '\n';
        #endif

		Main();
        
        #ifdef SARTHAK_LOCAL
            cerr << "---------------" << '\n';
        #endif
	}

	timeIt();
	return 0;
}