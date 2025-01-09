#include<bits/stdc++.h>
using namespace std;

namespace Number_Theory {
    static bool initialized = false;

    static std::vector<bool> prime;
    static std::vector<int> primes;

    void init(int N = 10000000) {
        prime.assign(N + 1, true);

        prime[0] = prime[1] = false;
        primes = {};

        for(long long p = 0; p * p <= N; p++) {
            if(!prime[p]) continue;
            primes.emplace_back(p);
            for(long long y = 2 * p; y <= N; y += p) {
                prime[y] = false;
            }
        }
        initialized = true;
    }

	// list of { prime_factor, count }
	std::vector<std::pair<long long, long long>> factors(long long N) {
        if(!initialized) init();

		std::vector<std::pair<long long, long long>> facts;
		for(long long x = 2; x * x <= N; x++) {
			if(prime[x] && N%x == 0) {
				long long cnt = 0;
				while(N > 1 && N%x == 0) N /= x, cnt++;
				facts.emplace_back(x, cnt);
			}
		}
		if(N > 1) facts.emplace_back(N, 1);
		return facts;
	}

	// divisor of a number in sorted order
	std::vector<long long> divisors(long long N) {
		std::vector<long long> divs;
		for(long long x = 1; x * x <= N; x++) {
			if(N%x == 0) {
				divs.push_back(x); if(N / x != x) divs.push_back(N / x);
			}
		}
		if(divs.size()) std::sort(divs.begin(), divs.end());
		return divs;
	}

    long long binpower(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (__int128_t)result * base % mod;
        base = (__int128_t)base * base % mod;
        e >>= 1;
    }
    return result;
}

    bool check_composite(long long n, long long a, long long d, int s) {
        long long x = binpower(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (__int128_t)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    };

    bool MillerRabin(long long n, int iter=5) { // returns true if n is probably prime, else returns false.
        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        if (n < 4) return n == 2 || n == 3;

        int s = 0;
        long long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }

        for (int i = 0; i < iter; i++) {
            int a = 2 + rand() % (n - 3);
            if (check_composite(n, a, d, s)) return false;
        }
        return true;
    }
}
using namespace Number_Theory;
