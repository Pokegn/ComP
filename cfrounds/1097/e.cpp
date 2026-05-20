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

ll dfs(ll u, ll val, vector<ll> &wait, vector<vector<ll>> &grafo){
    if(grafo[u].size() == 0) return u;

    val+=wait[u];
    ll idx = (val%(grafo[u].size()));
    ll nextnode = grafo[u][idx];

    return dfs(nextnode, val, wait, grafo);
}

void solve(){
    ll n; cin >> n; ll q; cin >> q;
    vector<ll> par(n+1, 0);
    rep(i, 2, n+1) cin >> par[i];
    
    vector<ll> tpar(n+1, 0);
    rep(i, 2, n+1) cin >> tpar[i];
    vector<ll> wait(n+1, 0); //le voy a ir agregando a esta fokin madre estupida tonta fea tonta horrible
    rep(i, 2, n+1) wait[i] = tpar[i];
    
    vector<vector<ll>> son(n+1, vector<ll>(0));
    rep(i, 2, n+1) son[par[i]].push_back(i);
    //son[0] = {1};

    vector<vector<ll>> grafo(n+1, vector<ll>(0));

    rep(i, 2, n+1){
        int add = i;
        while(son[add].size() == 1){
            add = son[add][0];
            wait[add] += wait[par[add]];
        }
        grafo[par[i]].push_back(add);
    }
    //cout << endl;
    
            // for(int i = 1; i < n+1; i++){
            //     cout << i << ": ";
            //     for(auto x: grafo[i]) cout << x << ' ' << '(' << wait[x] << ')' << ' ';
            //     cout <<endl;
            // }
            // cout << endl;
    //return;

    while(q--){
        ll m; cin >> m; //la query
        cout << dfs(1ll, m, wait, grafo) << ' ';
    }
    cout << endl;
    return;   

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}