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


void solve(){
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
    //cout << "xd"; return;
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
    ll p = 0;
    ll q = 1;
    ll pi;

    for(int i=0; i<z; i++){
        q*=binom(k+pot[primes[i]], pot[primes[i]]);
        q%=MOD;
    }

    // cout << z << endl;
    // cout << pot[primes[0]] << pot[primes[1]];
    //return;
    while (true) { //iteramos sobre los divisores de n
        pi = 1;
        vector<ll> decrease(z);
        ll x = 1;
        for(int i=0; i<z; i++){
            x*=ala[{primes[i], v[i]}]; //construimos el divisor actual = x
            x%=MOD;
        }
        for(int i=0; i<z; i++){
            decrease[i] = pot[primes[i]]-v[i];//cuanto baja cada potencia
            pi*=binom(decrease[i]+k-1, decrease[i]);
            //cout << decrease[i]+k-1 << ' ' << decrease[i] << ' ' << binom(decrease[i]+k-1, decrease[i]) << endl;
            //cout << endl;
            pi%=MOD;
        }
        // cout << "xd " << pi  << ' ' << x << endl;
        // cout << endl;
        
        p += pi*x;
        p%=MOD;
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

    ll ans = p;
    ans *= (fexp(q, MOD-2, MOD)%MOD);
    ans%=MOD;
    cout << endl;
    cout << p << ' ' << q << endl;
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 20000; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = fexp(fact[i], MOD - 2, MOD);
        //inv[i] = MOD - (long long)(MOD / i) * inv[MOD % i] % MOD;
    }
    while(t--) solve();
    return 0;
}