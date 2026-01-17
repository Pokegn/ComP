#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vlli x(200010, 0);

void solve(){
    ll n,k; cin >> n >> k;
    vlli a(n); for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) x[a[i]]++;
    ll mex = 0;
    while(x[mex]>0) mex++;
    mex = min(mex, k-1);

    cout << mex << endl;

    for(int i=0; i<n; i++) x[a[i]] = 0;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}