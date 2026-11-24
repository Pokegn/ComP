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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}



void solve(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0,n) cin >> a[i];
    
    sort(all(a));
    vector<ll> cum(n);
    cum[0] = a[0];
    rep(i,1,n) cum[i] = cum[i-1] + a[i];

    ll ans = cum[n-1];
    rep(i, 0, n){
        ll curr = (i+1)*a[i] - cum[i];
        curr += (cum[n-1] - cum[i]) - (n-i-1)*a[i];
        ans = min(ans, curr);
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}