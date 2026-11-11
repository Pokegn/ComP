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

vector<vector<int>> g;
vector<bool> dfs_vis;
set<int> visited;

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
    visited.insert(u);
	for(int v : g[u])
		if(!dfs_vis[v])
			dfs(v);
}

int mindfs(int u) {
	if(dfs_vis[u])
		return 1000000;
	
    int mini = u;
	dfs_vis[u] = true;
	for(int v : g[u]){
		if(!dfs_vis[v]){
            mini = min(mindfs(v), mini);
        }
    }
    return mini;
}

void solve(){
    int n; cin >> n;
    g = vector<vector<int>>(n+1);
    dfs_vis = vector<bool>(n+1, false);

    rep(i, 0, n-1){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if((n%2) == 0){
        cout << n+1 << endl;
        return;
    }

    vector<bool> isGray(n+2, false);
    //n
    dfs_vis[n] = true;
    for(auto u: g[n]){
        visited.clear();
        dfs(u);
        for(auto x: visited){
            if(visited.find(n-x) == visited.end()) isGray[n] = true;
        }
    }

    dfs_vis = vector<bool>(n+1, false);
    int m = (n+1)/2;
    dfs_vis[m] = true;
    for(auto u: g[m]){
        visited.clear();
        dfs(u);
        for(auto x: visited){
            if(visited.find(n+1-x) == visited.end()) isGray[m] = true;
        }
    }

    if(isGray[n]){
         cout << n << endl;
         return;
    }

    if(isGray[(n+1)/2]){
        cout << n+1 << endl;
        return;
    }
    
    cout << n+2 << endl;
    return;

    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}