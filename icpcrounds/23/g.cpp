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


vector<vector<int>> primes(1000000, vector<int>(0));
int m= 1e6+1;
vector<bool> is_prime(m+1, true);
vector<int> allprimes(0);

long long fexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i]) {
            allprimes.push_back(i);
            for (int j = i; j <= m; j += i){
                is_prime[j] = false;
                primes[j].push_back(i);
            }
        }
    }

    int n; cin >> n;
    map<pair<int,int>, int> pot;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++){
        int temp = a[i];
        for(auto p: primes[a[i]]){
            while(temp%p == 0){
                temp/=p;
                pot[{i,p}]++;
            }
        }
    }                                                       //calcula los divisores bien

    for(int i=0; i<n; i++){
        int temp = a[i];
        for(auto p: allprimes){
            pot[{i,p}] = pot[{i-1,p}] + pot[{i,p}];
        }        
    }                                           

    int q; cin >> q;
    for(int i=0; i<q; i++){
        int l,r; cin >> l >> r;
        l--; r--;
        ll ans = 1;
        for(auto p: allprimes){
            if(pot[{r,p}] == 0) continue;
            int exp = pot[{r,p}] - pot[{l-1, p}];
            if(exp == 0) continue;
            ans*=p-1; ans%=MOD;
            ans*=fexp(p, (ll)exp-1, MOD);
            ans%=MOD;
        }
        cout << ans << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}