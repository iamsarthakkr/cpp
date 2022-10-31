#include<bits/stdc++.h>
namespace NumberTheory {
	long long m_size = 0;
	std::vector<bool> is_prime;

	void genPrimes(int N) {
		m_size = N;
		is_prime.assign(N + 1, true);
		is_prime[0] = is_prime[1] = false;
		for(int x = 0; x * x <= N; x++) {
			if(is_prime[x]) {
				for(int y = 2 * x; y <= N; y += x) is_prime[y] = false;
			}
		}
	}

	// vector of {Factor, count}
	std::vector<std::pair<long long, long long>> factors(long long N) {
		assert(m_size > 0); assert(N >= 0 && m_size * m_size >= N);

		std::vector<std::pair<long long, long long>> facts;
		for(long long x = 2; x * x <= N; x++) {
			if(is_prime[x] && N%x == 0) {
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
}
using namespace NumberTheory;