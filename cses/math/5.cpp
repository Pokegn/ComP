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
vector<int> divs(1e6+1, 0);
vector<int> ndivs;

void solve(){
    ll n; cin >> n;
    ll ans = 1;
    ndivs = vector<int>(1, 1);
    int norig = n;

    for(auto p: primes){
        if(n==1) break;
        int count = 0;
        while(n%p==0){
            n/=p;
            count++;
        } 
        int sz = ndivs.size();
        int ppot = 1;
        for(int i=0; i<sz; i++){
            ppot = 1;
            for(int j = 0; j<count; j++){
                ppot *=p;
                ndivs.push_back(ndivs[i]*ppot);
            }
        }
    }
    int sz = ndivs.size();
    if(n!=1){
        for(int i=0; i<sz; i++){
            ndivs.push_back(ndivs[i]*n);
        }
    }
    for(auto x: ndivs) divs[x]++;

    // cout << n << endl;
    // for(auto x: ndivs) cout << x << ' ';
    // cout << endl;

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
    cin >> t;
    while(t--) solve();
    ll ans = 1;
    for(int i=1; i<=1000000; i++){
        if(divs[i]>1) ans = i;
    }
    cout <<ans << endl;
    return 0;
}