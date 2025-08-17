#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const string charSet = "abcdefghijklmnopqrstuvwxyz";

inline mt19937& rng() {
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return rng;
}

// Sinh số nguyên trong đoạn [l, r]
inline ll Rand(ll l, ll r) {
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng());
}

template<typename T>
inline T randChoice(const vector<T>& v) {
    if (v.empty()) throw runtime_error("Empty vector");
    int idx = Rand(0, (int)v.size() - 1);
    return v[idx];
}

template<typename T>
inline void randShuffle(vector<T>& v) {
    shuffle(v.begin(), v.end(), rng());
}

inline vector<ll> randArr(int n, ll l, ll r) {
    vector<ll> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = Rand(l, r);
    return res;
}

inline string randStr(int len) {
    string res;
    res.reserve(len);
    for (int i = 0; i < len; i++)
        res += charSet[Rand(0, (int)charSet.size() - 1)];
    return res;
}

inline vector<int> randPerm(int n) {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    randShuffle(p);
    return p;
}

inline vector<pii> randgraph(int n, int m) {
    if (m > n * (n - 1) / 2) throw runtime_error("Too many edges");

    set<pii> G;
    while ((int)G.size() < m) {
        int u = Rand(0, n - 1);
        int v = Rand(0, n - 1);
        if (u == v) continue;
        if (u > v) swap(u, v);
        G.emplace(u, v);
    }
    return vector<pii>(G.begin(), G.end());
}