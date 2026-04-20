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
#define MOD 1000000007


ll fact[200001];
ll inv[200001];

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
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}


void solve(){
    int n; cin >> n;
    vector<ll> a(n, 0), b(n+1);
    rep(i, 1, n+1) cin >> b[i];
    vector<ll> todosmenos(n+1, 0); //todosmenos[i] -> lo tienen n-i weones
    
    rep(i, 0, n) todosmenos[i] = b[n-i];

    
    rep(i, 0, n){
        if(todosmenos[i] != 0){
            rep(j, i+1, n){
                todosmenos[j] -= todosmenos[i]*binomial_coefficient(n - i, j-i);
                todosmenos[j] = ((todosmenos[j]%MOD)+MOD)%MOD;
            }
        }
    }
    
    ll suma = 0;
    
    // rep(i, 0, n){
    //     cout << todosmenos[i] << ' ';
    // }
    // cout << endl;
    rep(i, 0, n){
        suma+=todosmenos[i];
        a[i] = suma%MOD;
        cout << a[i] << ' ';
    }
    cout << endl;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 200001; i++)
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