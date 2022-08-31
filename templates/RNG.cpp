#include <random>
#include <chrono>

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
		return nextLongLong()%INT32_MAX;
	}

	int nextInt(int x) {
		return (int)nextLongLong(x);
	}

	int nextInt(int a, int b) {
		return nextLongLong(a, b);
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
