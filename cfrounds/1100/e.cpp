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
#define MOD 998244353

vector<vector<int>> g;
vector<int> parent;
vector<bool> dfs_vis;

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
	for(int v : g[u]){
		if(!dfs_vis[v]){
			dfs(v);
            parent[v] = u;
        }
    }
}

void solve(){
    int n; cin >> n;
    g = vector<vector<int>> (n);
    dfs_vis = vector<bool> (n, false);
    parent = vector<int>(n); parent[n-1] = n-1;
    rep(i, 0, n-1){
        int u,v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(i, 0, n){
        sort(all(g[i]), greater<int>());
    }

    dfs(n-1);
    vector<ll> ans(n, 0);

    priority_queue<int> toAdd; toAdd.push(n-1);
    while(!toAdd.empty()){
        auto u = toAdd.top();
        toAdd.pop();
        for(auto v: g[u]){
            if(v == parent[u]) continue;
            toAdd.push(v);
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}