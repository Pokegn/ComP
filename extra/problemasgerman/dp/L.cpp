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

lli n;
vlli a;
vlli sumaparcial;
vvlli loopans;

lli sumarango(lli l, lli r){
    return sumaparcial[r]-sumaparcial[l-1];
}

lli loop(lli l, lli r){
    if(loopans[l][r] != -1) return loopans[l][r];
    if(l == r) return a[l];
    lli ret = 0;
    ret = max(sumarango(l, r)-loop(l+1, r), sumarango(l, r)-loop(l, r-1));
    loopans[l][r] = ret;
    return ret;
}

void solve(){
    cin >> n;
    a.assign(n+1, 0);
    forn(i, 1, n+1) cin >> a[i];
    sumaparcial.assign(n+1,0);
    forn(i, 1, n+1){
        sumaparcial[i] = sumaparcial[i-1]+a[i];
    }

    loopans.assign(n+1, vlli(n+1, -1));

    //cout << loop(1, n)<< nl;

    cout << 2*loop(1, n) - sumarango(1, n) << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}