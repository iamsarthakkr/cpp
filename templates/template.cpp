#include <iostream>
#include <cassert>
#include <climits>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <string>
#include <math.h>
#include <random>
#include <chrono>
#include <time.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifdef SARTHAK_LOCAL
#include "C:\Users\sarthak\cpp\debug.h"
#else 
#define debug(...) 69
#endif

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = (end - start);
        float ms = duration.count() * 1000.0f;
        cerr << ms << "ms\n";
    }
};

namespace Random {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    long long nextInt() {
        return rng();
    }

    long long nextInt(long long x) {
        return std::uniform_int_distribution<long long>(0, x - 1)(rng);
    }

    long long nextInt(long long a, long long b) {
        return std::uniform_int_distribution<long long>(a, b - 1)(rng);
    }

    bool nextBoolean() {
        return nextInt(2);
    }

    vector<int> nextVector(int n, int mx = 1e9) {
        vector<int> a(n);
        for (int& x : a) x = nextInt(mx + 1);
        return a;
    }

    vector<long long> nextVector(int n, long long mx = 1e18) {
        vector<long long> a(n);
        for (long long& x : a) x = nextInt(mx + 1);
        return a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef SARTHAK_LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}