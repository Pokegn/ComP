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

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
	for(int v : g[u])
		if(!dfs_vis[v])
			dfs(v);
}

void solve(){
    int n, m; cin >> n >> m;
    g = vector<vector<int>> (n);
    
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(i, 0, n){
        if(sz(g[i]) == 0){
            cout << "Brain Melt" << endl;
            return;
        }
    }

    vector<int> unos;
    int many = 0;
    rep(i, 0, n){
        if(sz(g[i]) > 1){
            many++;
            // for(auto u: g[i]) if(sz(g[u]) > 1) many = 1;
        }
    }

    dfs_vis = vector<bool>(n, false);

    dfs(0);

    bool disjunto = 0;

    rep(i, 0, n) if(dfs_vis[i] == false) disjunto = true;

    if(many > 1 || disjunto){
        cout << "Many" << endl;
    }
    else{
        cout << "2" << endl;
    }
    return;


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}