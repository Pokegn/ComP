#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ll lcm(ll a, ll b){
    ll g = __gcd(a,b);
    return (a*b)/g;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<ll> c(n);
    c[0] = __gcd(a[0], a[1]);
    c[n-1] = __gcd(a[n-1], a[n-2]);
    rep(i, 1, n-1){
        c[i] = lcm(__gcd(a[i], a[i-1]), __gcd(a[i], a[i+1]));
    }
    ll ans = 0;
    rep(i, 0, n){
        if(c[i] < a[i] ) ans++;
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}