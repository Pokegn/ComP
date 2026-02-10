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

ll prod = 1; ll sum = 1; ll num = 1;
ll nummod = 1;

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

void solve(){
    ll n; cin >>n;
    vector<ll> p(n);
    vector<ll> k(n);
    vector<ll> pprod(n);
    vector<ll> numai(n); //sin i
    vector<ll> numdei(n); //sin i

    ll de = 1, hasta = 1;

    for(int i=0; i<n; i++){
        cin >> p[i] >> k[i];
        num*=(k[i]+1); num%=MOD;
        nummod*=(k[i]+1); nummod%=MOD-1;
        ll s = fexp(p[i], k[i]+1, MOD)-1; s%=MOD;
        s*= fexp(p[i]-1, MOD-2, MOD); s%=MOD;
        sum*=s; sum%=MOD;
    }

    for(int i=0; i<n; i++){
        numai[i] = hasta;
        hasta*=(k[i]+1);
        hasta%=(MOD-1);
        
    }

    for(int i=n-1; i>=0; i--){
        numdei[i] = de;
        de*=(k[i]+1);
        de%=(MOD-1);
    }

    for(int i=0; i<n; i++){
        k[i]%=(MOD-1);
        ll xp = (k[i])*(k[i]+1)/2;
        xp%=(MOD-1);
        //pprod[i] = fexp(p[i], xp, MOD);

        ll sinp = (numai[i]*numdei[i])%(MOD-1);
        //cout << p[i] << ' ' << sinp << endl;
        sinp%=(MOD-1);  
        xp*=sinp; xp%=(MOD-1);
        ll mult = fexp(p[i], xp, MOD);
        mult%=MOD;
        prod *= mult; prod%=MOD;
    }

    cout << num << ' ' <<sum <<' '<< prod << endl;
    return;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}