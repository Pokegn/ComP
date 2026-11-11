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

vector<vector<int>> grafo;
vector<bool> dfs_vis;
vector<int> p;
vector<pair<int, int>> dfsres;

pair<int, int> dfs(int u) { //sin y con
	if(dfs_vis[u]){
		return dfsres[u];
    }
	
    int ans1 = 0; //sin u
    int ans2 = 1; //con u
	dfs_vis[u] = true;
	for(int v : grafo[u]){
        if(!dfs_vis[v]){
            p[v] = u;
            pair<int, int> xd = dfs(v);
            ans1 += max(xd.fi, xd.se);
            ans2 += xd.fi;
        }
    }
    dfsres[u] = {ans1, ans2};
    return dfsres[u];
}

int getIdx(){
    int n; cin >> n;
    grafo = vector<vector<int>> (n);
    p = vector<int>(n, -1);
    dfs_vis = vector<bool>(n, false);
    dfsres = vector<pair<int, int>> (n);
    rep(i, 0, n-1){
        int u,v; cin >> u >> v;  u--; v--;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    if(n == 1) return -1;
    pair<int, int> ans = dfs(0);
    // cout << dfsres[0].fi << ' ' << dfsres[0].se << endl;
    if(ans.fi < ans.se){ //el MIS tiene a 0
        return grafo[0][0] + 1;
    }
    else{ //no tiene a 0
        return 1;
    }

}

void solve(){
    int k; cin >> k;
    int tree, idx = -1;
    rep(i, 0, k){
        int temp = getIdx();
        if(temp != -1){
            idx = temp;
            tree = i+1;
        }
    }

    if(idx == -1){
        rep(i, 1, k){
            cout << i << ' ' << 1 << ' ' << k << ' ' << 1 << endl;
        }
        return;
    }

    rep(i, 1, k+1){
        if(i == tree) continue;
        cout << i << ' ' << 1 << ' ' << tree << ' ' << idx << endl;
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