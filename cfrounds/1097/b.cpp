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
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    sort(all(a));

    map<ll, ll> is;
    rep(i, 0, n) is[a[i]] = 1;

    ll mex = 0;
    while(is[mex] == 1) mex++;
    ll maxx = 0;
    rep(i, 0, n) maxx = max(maxx, a[i]);
    ll ans = 0;
    ans += maxx*n;
    ans += (mex*(mex-1))/2;
    ans += (mex*(n-mex));
    if(maxx == mex-1) ans++;
    cout <<ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}