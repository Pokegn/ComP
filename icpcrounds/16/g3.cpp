#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
ll MOD = 1000000007;

ll fact[50001];
ll inv[50001];

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

ll binom(ll n, ll k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}


ll solve(ll n, ll k){
    ll m = n;
    vlli primes(0);
    map<ll, ll> pot;
    ll maxx = 4*1e7;
    for(int i=2; i<maxx; i++){
        if(m%i == 0){
            primes.push_back(i);
            while(m%i == 0){
                m/=i;
                pot[i]++;
            }
        }
    }

    map<pair<ll, ll>, ll> ala;
    for(auto p: primes){
        ll xd = pot[p];
        ll aaa = 1;
        for(int i=0; i<=xd; i++){
            ala[{p, i}] = aaa;
            aaa*=p;
        }
    }
    ll z = primes.size();
    vlli v(z, 0); //potencia de cada weon
    vector<ll> ndivs(0);

    while (true) { //iteramos sobre los divisores de n
        ll x = 1;
        for(int i=0; i<z; i++){
            x*=ala[{primes[i], v[i]}]; //construimos el divisor actual = x
        }
        ndivs.push_back(x);
        

        int pos = 0;
        while (pos < z) {
            if (v[pos] < pot[primes[pos]]) {
                v[pos]++;
                break;
            } else {
                v[pos] = 0;
                pos++;
            }
        }
        if (pos == z) break;
    }
    // cout << endl;
    // for(auto x:ndivs) cout << x << ' ';
    // return;

    map<ll, vector<ll>> divs;
    for(auto x: ndivs){
        divs[x] = vector<ll>(0);
        for(auto y: ndivs){
            if(x%y == 0){
                divs[x].push_back(y);
            }
        }
    }

    map<pair<ll, ll>, ll> dp;
    for(auto x: ndivs) dp[{x,0}] = x;
    for(int i=1; i<=k; i++){
        for(auto x: ndivs){
            for(auto y: divs[x]){
                dp[{x, i}] += dp[{y, i-1}];
            }
            // cout << dp[{x,i}] << endl;
            // cout << divs[x].size() << ' ' << fexp(divs[x].size(), MOD-2, MOD) << endl;
            dp[{x,i}]%=MOD;
            dp[{x, i}] *= fexp(divs[x].size(), MOD-2, MOD);
            dp[{x,i}]%=MOD;
        }
    }

    return dp[{n, k}];

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
        ll n,k; cin >> n >> k;
    ll m = n;
    vlli primes(0);
    map<ll, ll> pot;
    ll maxx = 4*1e7;
    for(int i=2; i<maxx; i++){
        if(m%i == 0){
            primes.push_back(i);
            while(m%i == 0){
                m/=i;
                pot[i]++;
            }
        }
    }
    if(m>1){
        primes.push_back(m);
        pot[m]++;
    }

    map<pair<ll, ll>, ll> ala;
    for(auto p: primes){
        ll xd = pot[p];
        ll aaa = 1;
        for(int i=0; i<=xd; i++){
            ala[{p, i}] = aaa;
            aaa*=p;
        }
    }
    ll c = 1;
    for(int i=0; i<primes.size(); i++){
        ll p = primes[i];
        c*=solve(ala[{p,pot[p]}], k);
        c%=MOD;
    }
    cout << c << endl;
    return 0;
}