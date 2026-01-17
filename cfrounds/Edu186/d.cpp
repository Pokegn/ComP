#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
#define MOD 998244353

ll fact[200];
ll inv[200];

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
}

ll binomial_coefficient(ll n, ll k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void solve(){
    ll n; cin >> n;
    vlli a(n+1, 0);
    for(int i=0; i<n+1; i++) cin >> a[i];

    ll maxi = 0;
    for(int i=1; i<n+1; i++) maxi = max(maxi, a[i]);
    ll maxcnt = 0;
    for(int i=1; i<n+1; i++){
        if(a[i] == maxi) maxcnt++;
    }

    ll s= 0;
    for(int i=1; i<n+1; i++) s+=a[i];

    vector<ll> possible(n+1, 0);
    for(int i=1; i<n+1; i++){
        //cout << "madre " << n*maxi-s-n+i << endl;
        if(a[0] >= n*maxi - s - n + i) possible[i] = 1;
    }
    // cout << "yay" << endl;
    // return;
    vector<ll> ways(n+1, 0);
    for(int i=1; i<n+1; i++){
        if(maxcnt > i) continue;
        ways[i] = binomial_coefficient(i-1, maxcnt-1);
    }

    ll ans = 0;
    for(int i=1; i<n+1; i++){
        //cout << "poss ";
        //if(possible[i] == 1) cout << i << ' ';
        ans+=ways[i]*possible[i];
    }
    //cout << "ans1 " << ans << endl;
    ans%=MOD;
    ans*= fact[maxcnt];
    ans%=MOD;
    ans*= fact[n-maxcnt];
    ans%=MOD;

    cout << ans << endl;


}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 200; i++)
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