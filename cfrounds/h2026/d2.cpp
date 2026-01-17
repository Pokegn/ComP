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
    vvlli depthcount(n+2, vlli(0));
    vlli depth(n+1, 0);
    vlli parent(n+1, -1);
	ll dep = 0;
	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();
            depthcount[dep].push_back(u);
            depth[u] = dep;

			for(int v : grafo[u]){
				if(!bfs_vis[v]) {
					bfs.push(v);
                    parent[v] = u;
					bfs_vis[v] = true;
				}
			}
		}
		dep++;
	}

    ll ans = -1;
    ans = max({ans,(ll)grafo[1].size()+1,(ll)depthcount[depth[1]].size()});
    for(ll v = 1; v<=n; v++){
        ans = max({ans,(ll)grafo[v].size(),(ll)depthcount[depth[v]].size()});
    }

    cout << ans << endl;

    vlli located(n+1, -1);
    bfs_vis = vector<bool>(n+1, false);
    bfs.push(1); bfs_vis[1] = true;
    dep = 0;
    located[1] = 0;
    
    vlli baneados;
    vector<pair<ll, ll>> dondemeto; //donde meto para cubrir los bans
    map<ll, bool> isban;

    while(!bfs.empty()) {
        int bfssz = bfs.size();
        baneados = vlli(0);
        dondemeto = vector<pair<ll, ll>>(0);
        while(bfssz--) {
            int u = bfs.front();
            bfs.pop();
            
            if(!isban[parent[u]]){
                isban[parent[u]] = true;
                baneados.push_back(parent[u]);
                dondemeto.push_back({u, baneados.size()});
            }

            for(int v : grafo[u]){
                if(!bfs_vis[v]) {
                    bfs.push(v);
                    bfs_vis[v] = true;
                }
            }
        }

        if(dep !=0 && depthcount[dep].size() > 0){ // pongo donde estan los baneados primero
            vector<bool> occupied(ans, false);
            for(auto x: baneados){
                occupied[located[x]] = true;
            }
            if(baneados.size()>1) for(auto x: dondemeto){
                ll escojo = (x.second)%(baneados.size());
                located[x.first] = located[baneados[escojo]];
                occupied[located[x.first]] = true;
            }
            else{
                occupied[located[parent[depthcount[dep][0]]]] = true;
            }
            ll idx = 0;
            for(auto x: depthcount[dep]){
                if(located[x]!=-1) continue;
                while(occupied[idx]) idx++;
                located[x] = idx;
                idx++;
            }
        }

        dep++;
    }

    vvlli gpo(ans, vlli(0));

    for(ll i=1; i<=n; i++){
        gpo[located[i]].push_back(i);
    }

    for(ll i=0; i<ans; i++){
        cout << gpo[i].size() << ' ';
        for(auto x: gpo[i]){
            cout << x << ' ';
        }
        cout << endl;
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}