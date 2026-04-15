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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<pair<int, int>>> grafo;
vector<bool> dfs_vis;
vector<int> parent, rrank;

void make_set(int v) {
    parent[v] = v;
    rrank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rrank[a] < rrank[b])
            swap(a, b);
        parent[b] = a;
        if (rrank[a] == rrank[b])
            rrank[a]++;
    }
}

// void pfill(int u, vector<int> &P) {
// 	if(dfs_vis[u])
// 		return;
	
// 	dfs_vis[u] = true;
// 	for(auto v : grafo[u]){
// 		if(!dfs_vis[v.fi]){
// 			pfill(v.fi, P);
//             P[v.fi] = u;
//         }
//     }
// }

vector<vector<int>> jmpval;

vector<vector<int>> treeJump(vector<int>& P){
    int on = 1, d = 1;
    while(on < sz(P)) on*=2, d++;
    vector<vector<int>> jmp(d,P);
    rep(i, 1, d) rep(j, 0, sz(P)) jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vector<int>> &tbl, int nod, int steps){
    rep(i, 0, sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int maxedge(vector<vector<int>> &tbl, int nod, int steps){
    rep(i, 0, sz(tbl))
}

int lca(vector<vector<int>> &tbl, vector<int>& depth, int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if(a == b) return a;
    for(int i = sz(tbl); i--;){
        int c = tbl[i][a], d = tbl[i][b];
        if(c!= d) a = c, b = d;
    }
    return tbl[0][a];
}

void filldepth(vector<int> &depth, int u){
    if(depth[parent[u]] == -1){
        filldepth(depth, parent[u]);
    }
    depth[u] = depth[parent[u]]+1;
}

int maxval(vector<vector<int>> &tbl, vector<int>& depth, int u, int v){
    int p = lca(tbl, depth, u, v);
}

void solve(){
    int n,m; cin >> n >> m;
    grafo = vector<vector<pair<int, int>>>(n);
    auto edges = vector<pair<int, pair<int, int>>>(n);
    rep(i, 0, m){
        int u,v,w; cin >> u >> v; u--; v--;
        grafo[u].push_back({v,w});
        grafo[v].push_back({u,w});
        edges.push_back({w, {u, v}});
        edges.push_back({w, {v, w}});
    }

    int cost = 0;
    vector<pair<int, pair<int, int>>> mst;
    parent.resize(n);
    rrank.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (find_set(e.se.fi) != find_set(e.se.se)) {
            cost += e.fi;
            mst.push_back(e);
            union_sets(e.se.fi, e.se.se);
        }
    }
    
    vector<vector<int>> jump = treeJump(parent);

    vector<int> depth(n, -1); depth[0] = 0;
    rep(i, 1, n) filldepth(depth, i);

    //ya tengo el mst y el jump, ahora me mato
    int ans = 0;
    for(auto e : edges){
        if()
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}