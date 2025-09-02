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
    lli k; cin >> k;
    lli ns = (k+1000000)/999999;
    if((k+1000000 % 999999) != 0) ns++;
    vlli a(ns, 1000000);
    a[0] = -1;
    lli s = 0;
    forn(i, 0, ns){
        s+=a[i];
    }
    a[ns-1] -= s;
    a[ns-1] += k+ns-1;

    cout << ns << nl;

    forn(i, 0, ns) cout << a[i] << ' ';
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}