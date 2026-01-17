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

vector<ll> rcount;
vlli ge;
vlli c;

ll fact[2000];
ll inv[2000];

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

ll ans(ll x, int limit){


    if(x == 0){

    }
    
    int m = msb(x);
    ll pot = 1<<m;
    auto x = *lower_bound(c.begin(), c.end(), pot);

    ll ret = 0;

    ret+= fexp(2, 

    //si agarro uno con mas de m gano
    ll pick = ge[m+1];
    if(limit<61) pick -= (ge[limit]); //mi limite es el minimo que no puedo agarrar que en este caso es 

    ret+= fexp(2, ge[m+1], MOD)-1;
    ret%=MOD;
    if(rcount[m] > 1) ret+= MOD + fexp(2, rcount[m], MOD) - rcount[m] - 1;
    ret%=MOD;
    ret+= ans(x-fexp(2, m-1, MOD), m);
    ret%=MOD;
    return ret;
}

void solve(){
    int n,m; cin >> n>> m;
    c = vlli (n);
    for(int i=0; i<n; i++) cin >> c[i];
    
    rcount = vector<ll> (61, 0);
    ge = vlli (61, 0);
    for(int i=0; i<n; i++) rcount[c[i]]++;

    ge[60] = rcount[60];
    for(int i=59; i>=0; i--){
        ge[i] = rcount[i] + ge[i+1];
    }
    string s;
    ll x;


    while(m--){
        cin >> s >> x;
        if(s == "1"){
            rcount[x]++;
            for(int i=60; i>=x; i--) ge[i]++;
        }
        if(s == "2"){
            rcount[x]--;
            for(int i=60; i>=x; i--) ge[i]--;
        }
        if(s == "3"){
            cout << ans(x, 61) << endl;
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 2000; i++)
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