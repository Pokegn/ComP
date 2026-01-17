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

void solve(){
    ll w,h,d,n;  cin >> w>> h >> d >> n;
    ll maxw = 1, maxh = 1, maxd = 1;

    bool isprime = true;
    for(ll i=1; i*i<=n; i++){
        if(n%i != 0) continue;
        isprime = false;
        if(w%i == 0){
            maxw = max(i,maxw);
        }
        if(h%i == 0){
            maxh = max(i,maxh);
        }
        if(d%i == 0){
            maxd = max(i,maxd);
        }
        if(w%(n/i) == 0){
            maxw = max((n/i),maxw);
        }
        if(h%(n/i) == 0){
            maxh = max((n/i),maxh);
        }
        if(d%(n/i) == 0){
            maxd = max((n/i),maxd);
        }
    }

    ll gcdw = __gcd(maxw, n);
    n/=gcdw;

    ll gcdh = __gcd(maxh, n);
    n/=gcdh;

    ll gcdd = __gcd(maxd, n);
    n/=gcdd;

    if(n == 1){
        cout << gcdw-1 << ' ' << gcdh-1 << ' ' << gcdd-1 << endl;
        return;
    }
    else{
        cout << -1 << endl;
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}