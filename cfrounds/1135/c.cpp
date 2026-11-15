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
#define MOD 1000000007

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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    map<ll, ll> occ;
    ll lim = -1;
    rep(i, 0, n){
        occ[a[i]]++;
        if(occ[a[i]] > 1) lim = max(lim, a[i]); 
    }

    vector<ll> change;
    rep(i, 0, n) if(a[i] > lim) change.push_back(a[i]);

    sort(all(change), greater<int>());

    if(change.empty()){
        cout << 1 << endl;
        return;
    }

    int szz = sz(change);
    change.push_back(lim);

    ll ans = 1;
    rep(i, 0, szz){
        ll maxi = change[i]; //todos deben ser  menores a change[i] menos change[i] que puede ser igual
        ll add = fexp(change[i]-1, (ll)i+1, MOD);
        // add *= change[i];
        add %= MOD;
        ans += add;
        ans %=MOD;
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