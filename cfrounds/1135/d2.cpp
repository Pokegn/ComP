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

ll fact[500001];
ll inv[500001];

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

ll binomial_coefficient(ll n, ll k) {
    if(k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void solve(){
    ll n,m,q; cin >> n >> m >> q;
    vector<ll> a(n); rep( i, 0, n) cin >> a[i];

    ll lim = n/2;
    vector<ll> need(lim);
    ll l = 0, r = 0;
    rep(i, 0, lim){
        l += a[i], r += a[n-i-1];
        need[i] = r - l; //necesito esto extra a la izq para igualar
    }

    map<ll, ll> freq;
    for(auto x: need) freq[x]++;

    if(n == 1){
        int x, y;
        rep(i, 0, q) cin >> x >> y;
        rep(i, 0, q){
            cout << 1 << endl;
        }
        return;
    }

    vector<vector<pair<ll, ll>>> queries(lim);
    rep(i, 0, q){
        ll idx, val;
        cin >> idx >> val;
        idx--;
        if(idx >= (n/2)){
            if(n%2 == 1 && idx == n/2){
                queries[idx-1].push_back({i,0});
                continue;
            }
            idx = (n-1-idx);
            val*=-1;            
        }
        queries[idx].push_back({i, val});
    }

    vector<ll> norm(n/2, 0);
    ll curr = 0;
    rep(i, 0, lim){
        if(need[i] == 0) curr++;
        norm[i] = curr;
    }
    
    map<ll, ll> areGood;
    
    vector<ll> ans(q);
    for(ll i = lim-1; i>=0; i--){
        areGood[need[i]]++;
        for(auto query: queries[i]){
            ll idx = query.fi;
            ll val = query.se;
            
            ll res = areGood[val];
            if(i > 0) res += norm[i-1];
            ans[idx] = 2*res;
            if(n%2 == 0 && val == need[lim-1]) ans[idx]--;
        }
    }
    
    rep(i, 0, q){
        // cout << ans[i] << ' ' << m-1 << endl;
        cout << binomial_coefficient(ans[i], m-1)%MOD << endl;
    }
    return;
    // cout << "XD"; return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 500001; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = fexp(fact[i], MOD - 2, MOD);
        //inv[i] = MOD - (long long)(MOD / i) * inv[MOD % i] % MOD;
    }

    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}