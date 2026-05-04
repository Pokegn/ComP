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

vector<bool> dfs_vis;
vector<vector<ll>> val;
vector<vector<pair<ll, ll>>> grafo;
vector<pair<ll, ll>> par;
ll k;


void dfs(int u){
    if(dfs_vis[u]) return;
    dfs_vis[u] = true;
 
    vector<ll> difs;
    ll kmenos1 = 0, kmenos0 = 0;
    for(auto v: grafo[u]){ //{weight, node}
        if(v.se == par[u].se) continue;
        par[v.se] = {v.fi, u}; 

        ll w = v.fi;

        dfs(v.se);
        kmenos1 += val[v.se][0];
        difs.push_back(val[v.se][1] + v.fi - val[v.se][0]); //lo que gano al elegirlo aqui
    }

    sort(all(difs), greater<ll>());
    
    kmenos0 = kmenos1;
    rep(i, 0, difs.size()){
        if(i<k && difs[i] > 0){
            kmenos0 += difs[i];
        }
        if(i<k-1 && difs[i] > 0){
            kmenos1 += difs[i];
        }
    }
    val[u][0] = kmenos0;
    val[u][1] = kmenos1;
    return;
}

void solve(){
    ll n; cin >> n >> k;
    par = vector<pair<ll,ll>>(n);
    grafo = vector<vector<pair<ll, ll>>>(n);
    dfs_vis = vector<bool>(n, false);
    rep(i, 0, n-1){
        ll u,v,w; cin >> u >> v >> w; u--; v--;
        grafo[u].push_back({w,v});
        grafo[v].push_back({w,u});
    }

    val = vector<vector<ll>> (n, vector<ll>(2, 0));
    par[0] = {0, 0};

    dfs(0);
    cout << max(val[0][1], val[0][0]) << endl;
    return;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}