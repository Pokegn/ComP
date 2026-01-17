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
    vlli a(41); vlli b(41);
    a[0] = 1; b[0] = 1;
    for(int i=1; i<41; i++){
        a[i] = b[i-1];
        b[i] = a[i-1]+b[i-1];
        ll g = __gcd(a[i], b[i]);
        a[i]/=g;
        b[i]/=g;
    }
    int n; cin >> n;
    cout << a[n] << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}