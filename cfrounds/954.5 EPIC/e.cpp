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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vlli ans;
vlli distancetoleaf;
vvlli hijos;
vlli a;

void setdtl(int v){
    for(auto h: hijos[v]){
        setdtl(h);
        distancetoleaf[v] = min(distancetoleaf[v], distancetoleaf[h]+1);
    }
}

void recursion(int v){
    // if(distancetoleaf[v] == 0){
    //     ans[v] = 0;
    //     return;
    // }
    lli sumahijos=0;
    for(auto h: hijos[v]){
        recursion(h);
        ans[v]+=ans[h];
        sumahijos+=a[h];
    }
    ans[v] += (distancetoleaf[v])*(max(a[v]-sumahijos,(lli)0));
}

void solve(){
    int n; cin >> n;
    a.assign(n, 0);
    ans.assign(n, 0);
    vvlli grafo(n);
    int p;
    forn(i, 0, n) cin >> a[i];
    forn(i, 1, n){
        cin >> p;
        grafo[i].push_back(p-1);
        grafo[p-1].push_back(i);
    }

    vi parent(n,-1);
    queue<int> bfs;
    vector<bool> bfs_vis(n, false);
    bfs_vis[0] = true; bfs.push(0);
    vi dep(n); dep[0] = 0;
    hijos.assign(n, {});

    while(!bfs.empty()){
        int v = bfs.front();
        bfs.pop();
        for(auto u: grafo[v]){
            if(bfs_vis[u]) continue;
            hijos[v].push_back(u);
            bfs.push(u);
            bfs_vis[u] = true;
            dep[u] = dep[v]+1;
            parent[u] = v;
        }
    }

    // forn(i,0,n){
    //     cout << "hijos de " << i << ':' << ' ';
    //     for(auto u: hijos[i]){
    //         cout << u << ' ';
    //     }
    //     cout << nl;
    // }
    // return;

    //tengo parent, dep, y hijos.
    queue<int> q;
    forn(i, 0, n){
        if(hijos[i].size() == 0) q.push(i);
    }
    
    distancetoleaf.assign(n, 1e10);
    while(!q.empty()){
        auto x = q.front();
        distancetoleaf[x] = 0;
        q.pop();
    }

    setdtl(0);
    recursion(0);
    // forn(i, 0, n){
    //     cout << ans[i] << ' ';
    // }
    // cout << nl;
    // return;
    cout << ans[0] << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}