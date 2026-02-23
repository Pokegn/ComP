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

int m = 1e6;
vector<bool> is_prime(m+1, true);
vector<ll> primes;

ll lcm(vector<ll> a){
    vector<ll> pot(primes.size(), 0);
    for(auto x:a){
        if(x==1) continue;
        vector<ll> xpot(primes.size(), 0);
        for(int j=0; j<primes.size(); j++){
            while(x%primes[j] == 0){
                xpot[j]++;
                x/=primes[j];
            }
            pot[j] = max(pot[j], xpot[j]);
        }
    }

    ll ans = 1;
    for(int i=0; i<primes.size(); i++){
        while(pot[i]>0){
            ans*=primes[i]; ans%=MOD;
            pot[i]--;
        }
    }
    return ans;
}

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
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++){ cin >> a[i]; a[i]--;}
    vector<bool> vis(n, false);
    vector<ll> sizes;
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        int sz = 1;
        int j = i;
        while(a[j]!=i){
            vis[j] = true;
            j = a[j];
            sz++;
        }
        vis[j] = true;
        sizes.push_back(sz);
    }

    ll g = sizes[0];
    for(int i=1; i<sizes.size(); i++){
        g = __gcd(g, sizes[i]);
    }

    ll ans = lcm(sizes);
    cout << ans << endl;
    return;
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

    while(t--) solve();
    return 0;
}