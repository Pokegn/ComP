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
#define MOD 998244353
 

bool customComparison(pair<ll, ll> a, pair<ll, ll> b)
{
    return (ll)a.fi*b.se < b.fi*a.se; 
}

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
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    vector<ll> b(n); rep(i, 0, n) cin >> b[i];
    vector<pair<ll, ll>> ratio;
    rep(i, 0, n){
        rep(j, i+1, n){
            ratio.push_back({b[i], b[j]});
            ratio.push_back({b[j], b[i]});
        }
    }
    sort(all(ratio), customComparison);
     
    ll ans = 0;

    rep(i, 0, n){
        rep(j, i+1, n){
            pair<ll, ll> curr = {a[j], a[i]}; //quiero contar todos los que cumplan que a[j]/a[i] < b[x]/b[y]
            auto ub = upper_bound(all(ratio), curr, customComparison);
            if(ub == ratio.end()) continue;
            ans += ratio.size()-(ub-ratio.begin()); ans = (ans%MOD)+MOD; ans%=MOD;
        }
    }

    //cout << ans << ' ' << fexp(ratio.size(), MOD-2, MOD) << endl;
    ans = ans*fexp(ratio.size(), MOD-2, MOD); ans%=MOD; cout << ans << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}