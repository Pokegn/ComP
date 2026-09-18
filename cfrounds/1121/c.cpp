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
#define MOD 998244353
#define mod 998244353

ll fexp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
} //llamas fexp(x, m-2, m)

void solve(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    ll facto = 1;
    for(ll i = 2; i<n; i++){
        facto *= i;
        facto %= MOD;
    } //n-1!

    sort(all(a));
    reverse(all(a));
    vector<ll> b(n);
    ll suma = 0;
    rep(i, 0, n){
        suma += a[i];
        b[i] = suma;
    }
    ll ans = 0;
    rep(i,1,n){
        ll add = b[i-1] - a[i]*i;
        add = (add%MOD+MOD)%MOD;
        ll mult = facto*fexp((ll)i, MOD-2, MOD); mult%=MOD;
        ans += add * mult;
        ans%=MOD;
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