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
    int n; cin >> n;
    priority_queue<pair<ll, ll>> pq;
    rep(i, 0, n){
        ll f, t; cin >> f >> t;
        pq.push({t, f});
    }

    ll ans = 0;
    while(pq.size() > 1){
        auto ma = pq.top(); pq.pop();
        auto mi = pq.top(); pq.pop();
        if(ma.se < mi.se){
            ans += ma.se*ma.fi;
            pq.push({mi.fi, mi.se-ma.se});
        }
        else{
            ans += mi.se*ma.fi;
            pq.push({ma.fi, ma.se-mi.se});
        }
    }
    auto xd = pq.top();
    ans += xd.fi*xd.se;
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}