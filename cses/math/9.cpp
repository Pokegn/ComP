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

int m = 1e6+1;
vector<bool> is_prime(m+1, true);
vector<ll> primes;
vector<vector<ll>> d(1e6+1,vector<ll>(0));

void solve(){
    vector<ll> mobius(1e6+1, 1);
    for(auto p: primes){
        ll k = p;
        while(k <= 1e6){
            if(k%(p*p) == 0) mobius[k] = 0;
            else mobius[k]*=-1;
            k+=p;
        }
    }

    vector<ll> count(1e6+1, 0);

    ll n; cin >> n;
    vector<ll> a(n); for(ll i=0; i<n; i++) cin >> a[i];

    unordered_map<int, int> ina;
    for(auto x: a) ina[x] = 1;

    for (int i = 1; i * i < 1000001; i++) { //i y j/i dividen a j
        for (int j = i * i; j < 1000001; j += i) {
            if(!ina[j]) continue;
            d[j].push_back(i);
            if (j / i != i) d[j].push_back(j / i);  // Avoid duplicate for perfect squares
        }
    }

    for(ll i=0; i<n; i++){
        for(auto di: d[a[i]]){
            count[di]++;
        }
    }

    ll ans = 0;
    for(ll i=1; i<=1e6; i++){
        ans+= ((count[i]*(count[i]-1))/2)*mobius[i];
    }

    cout << ans << endl;
    

    //suma de i=0 a n-1 de suma de j>i de (mcd(a[i], a[j]) == 1
    //= suma de i=0 a n-1 de suma de j>i de suma de d|a[i], a[j] de mobius(d) 
    //= suma de d = 1 a 1e6 de mobius(d) * (multiplos de d en 2)


}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i] && (long long)i * i <= m) {
            for (int j = i * i; j <= m; j += i)
                is_prime[j] = false;
        }
    }
    for(int i=2; i<=m; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    //cin >> t;
    while(t--) solve();
    return 0;
}