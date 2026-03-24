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

vector<vector<int>> grafo;
vector<bool> dfs_vis;
vector<int> color;
bool flag;
int blancos;
int szz;

void dfs(int u) {
	if(dfs_vis[u])
		return;

    szz++;
    blancos+=color[u];
	dfs_vis[u] = true;
	for(int v : grafo[u]){
		if(!dfs_vis[v]){
            color[v] = 1-color[u];
            dfs(v);
        }
        else{
            if(color[v] == color[u]) flag = true;
        }

    }
			
}


void solve(){
    int n,m; cin >> n >> m;
    grafo = vector<vector<int>> (n);
    color = vector<int> (n, 0);
    dfs_vis = vector<bool> (n, false);

    rep(i, 0, m){
        int u,v; cin >> u >> v;
        grafo[u-1].push_back(v-1);
        grafo[v-1].push_back(u-1);
    }

    int ans = 0;

    rep(i, 0, n){
        if(!dfs_vis[i]){
            flag = false;
            blancos = 0;
            szz = 0;
            dfs(i);
            if(!flag) ans += max(blancos, szz-blancos);
            //cout << i << ' ' << blancos << ' ' << szz-blancos << endl;
        } 
    }

    cout << ans << endl;
    //cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}