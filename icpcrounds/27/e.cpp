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

ll suma(ll a, ll m){
    if(a == 0) return 0;
    ll ans =0;
    ll k;
    k = a/2;
    if(a%2 == 0){
        ans+=fexp(2,k+1, m);
        ans-=2;
    }
    else{
        ans+=fexp(2,k+1, m);
        ans+=fexp(2,k, m);
        ans-=2;
    }
    return (ans%m);
}

void solve(){
    ll l,r,m; cin >> l >> r >> m;
    ll ans = suma(r, m) - suma(l-1, m);
    ans = ((ans%m)+m)%m;
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}