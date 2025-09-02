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

//n personas, k candies, entonces quiero (n+k-1) en (n-1)

vvlli comb;

lli fillcomb(lli m, lli n){
    if(comb[m][n] != -1) return comb[m][n];
    if(m<n || m == 0) return 0;
    if(n == 0) return 1;

    return fillcomb(m-1, n-1) + fillcomb(m, n-1);
}

void solve(){
    lli n, k; cin >> n >> k;
    comb.assign(n+k, vlli(n, -1));
    comb[1][1] = 1;

    cout << fillcomb(n+k-1, n-1) << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}