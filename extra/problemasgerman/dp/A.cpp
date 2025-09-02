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
    lli n; cin >> n;
    vlli h(n); forn(i, 0, n) cin >> h[i];

    vlli ans(n);
    ans[0] = 0;
    ans[1] = abs(h[1]-h[0]);
    forn(i, 2, n){
        ans[i] = min(ans[i-1] + abs(h[i]-h[i-1]), ans[i-2]+abs(h[i]-h[i-2]));
    }
    cout << ans[n-1] << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}