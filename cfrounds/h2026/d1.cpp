#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<int>> grafo;

void solve(){
    int n; cin >> n;
	grafo.assign(n+1, {});

	int M = n-1;
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	vector<bool> bfs_vis(n+1, false);
	queue<int> bfs; bfs.push(1); bfs_vis[1] = true;
    vlli depthcount(n+2, 0);
    vlli depth(n+1, 0);
	ll dep = 0;
	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();
            depthcount[dep]++;
            depth[u] = dep;

			for(int v : grafo[u]){
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
				}
			}
		}
		dep++;
	}

    ll ans = -1;
    grafo[1].push_back(123123);
    for(ll v = 1; v<=n; v++){
        //cout << v << ' ' << grafo[v].size() << ' ' << depthcount[depth[v]] << endl;
        ans = max({ans,(ll)grafo[v].size(),depthcount[depth[v]]});
    }

    //cout << (ll)grafo[6].size() + depthcount()

    cout << ans << endl;

    // bfs_vis = vector<bool>(n+1, false);
	// bfs.push(1); bfs_vis[1] = true;
    // vlli depth(n+1, 0);
	// dep = 0;
	// while(!bfs.empty()) {
	// 	int bfssz = bfs.size();
	// 	while(bfssz--) {
	// 		int u = bfs.front();
	// 		bfs.pop();
    //         dep[];

	// 		for(int v : grafo[u]){
	// 			if(!bfs_vis[v]) {
	// 				bfs.push(v);
	// 				bfs_vis[v] = true;
	// 			}
	// 		}
	// 	}
	// 	dep++;
	// }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}