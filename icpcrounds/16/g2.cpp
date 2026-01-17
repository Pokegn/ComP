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

map<ll, ll> pot;
map<pair<ll, ll>, ll> ala;

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


ll solve(ll n, ll k){
    ll m = n;
    vlli primes(1, n);

    ll z = 1;
    ll v = 0; //potencia de cada weon

    //map<pair<ll, ll>, ll> dp;
    ll poo = pot[n];
    vector<vector<ll>> dp(poo+1, vector<ll>(k+1, 0));

    for(int i=0; i<=poo; i++) dp[i][0] = ala[{n, i}]; 
    for(int i=1; i<=k; i++){
        for(int j=0; j<=poo; j++){
            for(int k = 0; k<=j; k++){
                dp[j][i] += dp[k][i-1];
            }
            dp[j][i]%=MOD;
            dp[j][i]*= fexp(poo+1, MOD-2, MOD);
            dp[j][i]%=MOD;
        }
        }

    // cout <<  dp[{n, k}] << endl;
    return dp[poo][k];

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;


    ll n,k; cin >> n >> k;
    ll m = n;
    vlli primes(0);
    ll maxx = 6*1e7;
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
        ll solv = solve(p, k);
        //cout << p << ' ' << solv << ' ';
        c*=solv;
        c%=MOD;
    }
    cout << c << endl;

    return 0;
}