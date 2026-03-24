#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<int>> ingrafo, outgrafo;
vector<bool> dfs_vis;
vector<int> depth;

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
    if(outgrafo[u].size() > 1)
	for(int v : outgrafo[u]){
		if(!dfs_vis[v]){
			dfs(v);
        }
        if(ingrafo[v].size() > 1){
            depth[u] = max(depth[u], depth[v]+1);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    ingrafo = vector<vector<int>> (n);
    outgrafo = vector<vector<int>> (n);

    rep(i, 0, m){
        int u,v; cin >> u >> v;
        outgrafo[u-1].push_back(v-1);
        ingrafo[v-1].push_back(u-1);
    }

    depth = vector<int> (n, 1);
    dfs_vis = vector<bool> (n, false);

    rep(i, 0, n){
        if(!dfs_vis[i]) dfs(i);
    }

    //cout << endl;
    int ans = 0;
    rep(i, 0, n){
        //cout << i+1 << ' ' << depth[i] << endl;
        ans = max(depth[i], ans);
    }
    cout << ans << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}