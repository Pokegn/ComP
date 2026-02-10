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

int m = 1e3+1;
vector<bool> is_prime(m+1, true);
vector<int> primes;

void solve(){
    ll n; cin >> n;
    ll ans = 1;

    for(auto p: primes){
        if(n==1) break;
        int count = 0;
        while(n%p==0){
            n/=p;
            count++;
        } 
        ans*=(count+1);
    }
    if(n>1) ans*=2;

    cout << ans << endl;
    return;
}

int main(){
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
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}