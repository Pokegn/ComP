#include <bits/stdc++.h> //416608695821
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

int m = 1e6;
vector<bool> is_prime(m+1, true);
vector<ll> primes;

bool exprimo(ll n){
    for(auto p: primes){
        if(p*p>n) break;
        if(n%p == 0) return false;
    }
    return true;
}

void solve(){
    ll n; cin >> n;
    n++;
    while(!exprimo(n)) n++;
    cout << n << endl;
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
    cin >> t;
    while(t--) solve();
    return 0;
}