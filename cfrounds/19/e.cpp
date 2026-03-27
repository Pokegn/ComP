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

void solve(){
    ll n, m; cin >> n >> m;
    set<ll> sett;
    map<ll, ll> cantidad;
    vector<vector<ll>> a(n+1);
    rep(i, 0, n){
        ll x; cin >> x;
        cantidad[x]++;
        sett.insert(x);
    }
    vector<ll> vals;
    for(auto x: sett){
        a[cantidad[x]].push_back(x);
        vals.push_back(x);
    }
    set<pair<ll, ll>> malas;
    rep(i, 0, m){
        ll x,y; cin >> x >> y;
        malas.insert({x,y}), malas.insert({y,x});
    }
    for(auto x: sett) malas.insert({x,x});
    rep(i, 0, n+1) sort(all(a[i]), greater<ll>());
    
    ll ans = -1;
    
    // cout << "xd"; return;
    ll cant, sz, idx, ca;
    for(auto x: vals){
        ca = cantidad[x];
        for(cant = 0; cant <= ca; cant++){
            sz = a[cant].size();
            idx = 0;
            while(idx < sz && malas.count({a[cant][idx],x}) != 0) idx++;
            if(idx<sz && ans < (ca+cant)*(a[cant][idx]+x) && malas.count({a[cant][idx],x}) == 0) ans = max(ans, (ca+cant)*(a[cant][idx]+x));
        }
        //cant = ca
        //  cant = ca;
        //  sz = a[cant].size();
        //  idx = 0;
        // while(idx < sz && malas.count({a[cant][idx],x}) != 0) idx++;
        // if(idx<sz) ans = max(ans, (ca+cant)*(a[cant][idx]+x));
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}