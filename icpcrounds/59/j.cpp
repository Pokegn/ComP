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

int hopcroftKarp(vector<vi>& g, vi& r) {
int n = sz(g), res = 0;
vi l(n, -1), q(n), d(n);
auto dfs = [&](auto f, int u) -> bool {
int t = exchange(d[u], 0) + 1;
for (int v : g[u])
if (r[v] == -1 || (d[r[v]] == t && f(f, r[v])))
return l[u] = v, r[v] = u, 1;
return 0;
};
for (int t = 0, f = 0;; t = f = 0, d.assign(n, 0)) {
rep(i,0,n) if (l[i] == -1) q[t++] = i, d[i] = 1;
rep(i,0,t) for (int v : g[q[i]]) {
if (r[v] == -1) f = 1;
else if (!d[r[v]]) d[r[v]] = d[q[i]] + 1, q[t++] = r[v];
}
if (!f) return res;
rep(i,0,n) if (l[i] == -1) res += dfs(dfs, i);
}
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, 0, m){
        int u,v;
        ll d; cin >> u >> v >> d; u--; v--;
        g[u].push_back({v,d});
    }

    ll l = 0, r = 1000000001;
    vi match;
    vector<vi> grafo;
    while(l < r){
        match = vi(n, -1);
        grafo = vector<vi>(n, vi(0));
        ll mid = (l+r)/2;
        rep(i, 0, n){
            for(auto xd: g[i]){
                if(xd.se <= mid) grafo[i].push_back(xd.fi);
            }
        }
        int lol = hopcroftKarp(grafo, match);
        if(lol == n){ //si se puede con mid
            r = mid;
        }
        else l = mid+1; //ocupo mas
    }
    if(l == 1000000001) cout << -1 << endl;
    else
    cout << l << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}