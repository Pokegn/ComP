#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<int>> grafo;
vector<bool> dfs_vis;
    // vi nextpos; //tengo que calcular solo estos tres
    // vi nextneg;
    vi nexti;
    vlli a;
    vlli ans;
vlli b;

void dfs(int u) {
    if(dfs_vis[u])
        return;
    
    dfs_vis[u] = true;
    if(grafo[u].size() == 1 && u!=1){
        ans[u] = 0;
        return;
    }
    for(int v : grafo[u]){
        if(!dfs_vis[v]){
            dfs(v);
            if(ans[v]+a[u]*b[v] < ans[u]) nexti[u] = v;
            ans[u] = min(ans[u], ans[v]+a[u]*b[v]);
            for(int w: grafo[v]){
                if(w == u) continue;
                if(ans[w]+a[u]*b[w] < ans[u]) nexti[u] = w;
                ans[u] = min(ans[u], ans[w]+a[u]*b[w]);
            }
            if(nexti[v]!=-1){
                if(ans[u]>ans[nexti[v]]+a[u]*b[nexti[v]]) nexti[u] = nexti[v];
                ans[u] = min(ans[u], ans[nexti[v]]+a[u]*b[nexti[v]]);
            }
        }
    }
}

void solve(){

    int N; cin >> N;
    grafo.assign(N+1, {});
    dfs_vis.assign(N+1, false);
    // nextpos.assign(N+1, -1);
    // nextneg.assign(N+1, -1);
    nexti.assign(N+1, -1);
    a.assign(N+1, 0);
    b.assign(N+1, 0);
    ans.assign(N+1, 1e10);

    forn(i, 1, N+1){
        cin >> a[i];
    }
    forn(i, 1, N+1){
        cin >> b[i];
    }

    int M = N-1;
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    dfs(1);
    forn(i, 1, N+1) cout << ans[i] << ' ';
    cout << nl;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}