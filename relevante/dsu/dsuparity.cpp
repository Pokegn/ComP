#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

const int MAXN = 1e6+1;
pii parent[MAXN];
int sizee[MAXN];
int bipartite[MAXN];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    sizee[v] = 1; bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    auto [pa, x] = find_set(a);
    auto [pb, y] = find_set(b);
    if (pa == pb) if (x == y) bipartite[a] = false;
    else {
        if (sizee[pa] < sizee[pb]) swap(pa, pb);
        parent[pb] = make_pair(pa, x ^ y ^ 1);
        bipartite[pa] &= bipartite[pb];
        sizee[pa] += sizee[pb];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}