#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
// #define sz(x) (int) (x).size()
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
vector<int> color;
vector<bool> vis;

void dfs(int u){
    if(vis[u]) return;
    vis[u] = true;
    
    bool has0 = false, has1 = false;

    for(auto v: g[u]){
        if(v == u){
            has0 = true; has1 = true;
        }
        if(!vis[v]) continue;
        if(color[v] == 0) has0 = true;
        if(color[v] == 1) has1 = true;
    }

    if(has0){
        color[u] = 1;
        if(has1) color[u] = 2;
    }

    for(auto v: g[u]){
        dfs(v);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    
    // vector<pair<ll, ll>> as;
    // rep(i, 0, n) as.push_back({a[i], i});
    // sort(all(as));
    sort(all(a));
    vector<ll> vals = a;
    
    auto it = unique(all(vals));
    vals.resize(std::distance(vals.begin(), it));
    int sz = vals.size();
    // for(auto va: vals) cout << va << ' '; cout << endl; return;
    vector<vector<ll>> indices(sz);
    vector<ll> cnt(sz, 0);
    color = vi(sz, 0);
    vis = vector<bool>(sz, false);
    int idx = 0;
    rep(i, 0, n){
        while(a[i] != vals[idx]) idx++;
        cnt[idx]++;
        indices[idx].push_back(i);
    }
    
    g = vector<vector<int>> (sz);
    vector<ll> res = cnt;
    vector<pair<int, int>> edges;
    //vals, cnt
    int lol = 0;

    rep(j, 0, m){
        int r = sz-1;
        rep(l, 0, r+1){
            while(r >= 0 && vals[l] + vals[r] > b[j]) r--;
            if(r<l) continue;
            if(vals[l] + vals[r] == b[j]){
                if(l == r){
                    res[l] = 0;
                    lol += cnt[l];
                } 
                else{
                    edges.push_back({l, r});
                }
            }
        }
    }


    for(auto e: edges){
        auto i = e.fi;
        auto j = e.se;
        int quito = min(res[i], res[j]);
        res[i] -=quito;
        res[j] -=quito;
        lol+= 2*quito;
    }

    cout << lol << endl;
    rep(i, 0, sz){
        rep(j, 0, cnt[i]-res[i]) cout << vals[i] << ' ';
    }
    cout << endl;
    return;

    
    
    
    // rep(i, 0, sz) dfs(i);
    // int choose1 = 0, choose0 = 0;
    // rep(i, 0, sz){
    //     if(color[i] == 0){
    //         choose0 += cnt[i];
    //     }
    //     if(color[i] == 1){
    //         choose1 += cnt[i];
    //     }
    //     if(color[i] == 2){
    //         choose0 += cnt[i];
    //         choose1 += cnt[i];
    //     }
    // }
    // for(auto cc: color) cout << cc << ' ';
    // cout<< endl; return;
    
    // if(choose0 < choose1){
    //     cout << choose0 << endl;
    //     rep(i, 0, sz){
    //         if(color[i] == 0 || color[i] == 2){
    //             for(auto v: indices[i]) cout << a[v] << ' ';
    //         } 
    //     }
    //     cout << endl;
    // }
    // else{
    //     cout << choose1 << endl;
    //     rep(i, 0, sz){
    //         if(color[i] == 1 || color[i] == 2){
    //             for(auto v: indices[i]) cout << a[v] << ' ';
    //         }
    //     }
    //     cout << endl;
    // }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}