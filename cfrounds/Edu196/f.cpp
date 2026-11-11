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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

const int MAXN = 1e6+1;
int parent[MAXN];
int sizee[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sizee[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

void solve(){
    int n; cin >> n;
    vector<pii> rang(n);
    rep(i, 1, n) cin >> rang[i].fi >> rang[i].se;
    rep(i, 0, n){
        rang[i].fi--;
        rang[i].se--;
    }

    for (int i = 0; i <= n; i++) {
        make_set(i);
    }

    vi answer(n, -1);

    for (int i = 1; i <n; i++) {
        int l = rang[i].fi;
        int r = rang[i].se;
        int c = i;
        for (int v = find_set(l); v <= r; v = find_set(v)) {
            answer[v] = c;
            parent[v] = v + 1;
        }
    } //answer tiene el primero que lo contiene

    rep(i, 1, n){
        
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}