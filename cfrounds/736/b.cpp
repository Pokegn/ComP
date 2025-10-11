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

vlli a;

lli ansrang(lli l, lli r){
    if(l == r) return 1;
    lli m = (l+r)/2;

    lli lans = ansrang(l, m);
    lli rans = ansrang(m+1, r);
    vlli prefix, suffix;
    suffix.push_back(a[m+1]);
    lli xd = suffix[0];
    while(xd > 1){
        
    }
}

void solve(){
    lli n; cin >> n; vlli xddddd(n);
    for(auto x: xddddd) cin >> x;
    a = vlli (n-1);
    forn(i, 0, n-1) a[i] = xddddd[i+1] - xddddd[i];



}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}