#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}


void solve(){
    lli n;
    vector<lli> primes(0);
    n = 100000;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (lli i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (lli j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }
    
    
    int m; cin >> m;
    if(m==2){
        cout << -1 << nl;
        return;
    }
    
    lli xd = 1;
    if(m<=10){
        forn(i, 0, m) xd *= primes[i];
        forn(i, 0, m){
            cout << xd/primes[i] << nl;
        }
    }
    else{
        vlli ans(0);
        forn(i, 0, 10) xd*= primes[i];
        forn(i, 0, 10){
            ans.push_back(xd/primes[i]);
        }
        forn(i, 0, 10){
            forn(j, 0, i){
                ans.push_back(xd/(primes[i]*primes[j]));
            }
        }
        forn(i, 0, m){
            cout << ans[i] << nl;
        }
    }


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}