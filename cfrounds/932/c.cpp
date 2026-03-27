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
    ll lim; cin >> lim;
    vector<pair<ll, ll>> a(n);
    rep(i, 0, n) cin >> a[i].second >> a[i].first;
    sort(all(a));
    ll ans = 0;

    rep(l, 0, n){
        priority_queue<ll> pq;
        ll sum = 0;
        rep(r, l, n){
            sum += a[r].se;
            pq.push(a[r].se);
            while(!pq.empty() && sum + a[r].fi - a[l].fi > lim){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, (ll)pq.size());
        }

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