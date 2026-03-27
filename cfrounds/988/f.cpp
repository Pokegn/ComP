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
vector<ll> h,x;
ll n,m,k; //m danito

bool able(ll t){ //si puedo matar a k en t tries
    vector<pair<ll, ll>> events;
    rep(i,0,n){
        ll quitar = h[i]/t; if(h[i]%t != 0) quitar++; //quito al menos lquitar
        if(quitar > m) continue;
        //el primero que si se puede
        ll l = x[i] - m + quitar;
        //el primero que no se puede despues de l
        ll r = x[i] + m - quitar + 1;
        events.push_back({l, 1});
        events.push_back({r, -1});
    }
    sort(all(events));
    ll xd = 0;
    for(auto a:events){
        xd += a.se;
        if(xd>=k) return true;
    }
    return false;
}

void solve(){
    cin>> n >> m >> k;
    h.resize(n); rep(i, 0, n) cin >> h[i];
    x.resize(n); rep(i, 0, n) cin >> x[i];

    ll l = 1, r = 1000000001;
    while(l < r){
        ll m = (l+r)/2;
        if(able(m)) r = m;
        else l = m+1;
    }
    if(l == 1000000001) cout << -1 << endl;
    else cout << l << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}