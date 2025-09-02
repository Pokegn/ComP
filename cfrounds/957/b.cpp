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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n,k; cin >> n >> k;
    vlli a(k);
    forn(i,0 ,k) cin >> a[i];
    lli unos = 0;
    lli sum = 0;
    lli maxi = 0;
    forn(i, 0, k){
        if(a[i] == 1) unos++;
        sum+=a[i];
        sum+=a[i]-1;
        maxi = max(maxi, a[i]);
    }
    sum-=2*maxi-1;
    cout << sum << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}