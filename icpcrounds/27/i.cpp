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
#define MOD 1000000007

ll fact[10000001];
ll inv[10000001];
ll invsolo[10000001];

ll binomial_coefficient(ll n, ll k) {
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void solve(){
    ll k,s,t; cin >> k >> s >> t;
    s-=k;
    if(s<0){
        cout << 0 << endl;
        return;
    }
    ll m,r;
    m = k/t;
    r = k%t;
    if(r == 0){
        if(s%(k/t) != 0){
            cout << 0 << endl;
            return;
        }
        s/=(k/t);
        ll ans = binomial_coefficient(s+t-1, s);
        cout << (MOD+ans)%MOD << endl;
        return;
    }
    ll curr = 0;
    pair<ll, ll> p;
    ll ans = 0;
    ll s1, s2;
    while(curr <= s){
        if((s-curr)%m == 0){
            s1 = curr/(m+1);
            s2 = (s-curr)/m;
            ans = (ans +(binomial_coefficient(r+s1-1, s1)*binomial_coefficient((t-r)+s2-1, s2)))%MOD;
        } 
        curr+=m+1;
    }
    
    cout << (ans+MOD)%MOD << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    invsolo[0] = 1;
    invsolo[1] = 1;
    for (ll i = 2; i < 10000001; ++i)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        invsolo[i] = -(ll)(MOD/i)*invsolo[MOD%i]%MOD;
        inv[i] = invsolo[i]*inv[i-1]%MOD;
    }
    solve();
}