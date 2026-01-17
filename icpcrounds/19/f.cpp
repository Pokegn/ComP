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

vector<vector<ll>> b;
ll t=1;

ll fexp(ll a, ll b, ll m) {
    a %= m;
    if(a==0) return 0;
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
    ll c; cin >> c;
    vector<ll> primes; //los c primos
    vector<ll> powers; //las c potencias
    vector<vector<ll>> ala(c, vector<ll>(53, 1));
    for(int i=0; i<c; i++){
        ll x; cin >> x;
        primes.push_back(x);
        cin >> x;
        powers.push_back(x);
    }

    for(int i=0; i<c; i++){
        for(int j=1; j<53; j++){
            ala[i][j] = ala[i][j-1]*primes[i];
            ala[i][j]%=MOD;
        }
    }

    ll ans = 2;
    ll n = 1;
    ll a,b,d;
    // ll i = 0;
    // cout << powers[i]*ala[i][powers[i]] << endl;
    // cout << (ala[i][powers[i]]*primes[i]-1)/(primes[i]-1) << endl;

    // return;
    for(int i=0; i<c; i++){
        a = (((ala[i][powers[i]]*primes[i]-1)%MOD)*(fexp(primes[i]-1, MOD-2, MOD)))%MOD + (powers[i]*ala[i][powers[i]])%MOD; //(p^(k+1)-1)/(p-1)+kp^k
        // cout << (ala[i][powers[i]]*primes[i]-1)/(primes[i]-1) << endl;
        // cout << powers[i]*ala[i][powers[i]] << endl;
        a%=MOD;

        b = ((n*(ala[i][powers[i]]-1))%MOD)*(fexp(primes[i]-1, MOD-2, MOD)); //n*(p^k-1)/(p-1)
        b%=MOD;
        d = (powers[i]*ala[i][powers[i]])%MOD; //n*k*p^k
        d*=n;
        d%=MOD;

        //cout << ans << ' ' << a << ' ' << b << ' ' << d << endl;
        ans = -b-d + ans*a;
        ans%=MOD;
        n*=ala[i][powers[i]];
        n%=MOD;
    }

    ans = (ans + MOD)%MOD;
    cout << "Case " << t << ": " << ans << endl;
    return;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll ti; cin >> ti;
    t = 1;
    while(t<=ti){
        solve();
        t++;
    }
    return 0;
}