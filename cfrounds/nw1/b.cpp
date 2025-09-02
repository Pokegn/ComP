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
    lli k, n; cin >> n >> k;
    vlli l(n), r(n);
    forn(i, 0, n) cin >> l[i];
    forn(i, 0, n) cin >> r[i];

    forn(i, 0, n){
        lli maxi = max(l[i], r[i]);
        lli mini = min(l[i], r[i]);
        l[i] = maxi;
        r[i] = mini;
    }

    sort(r.begin(), r.end(), greater<lli>());
    lli ans = 0;
    forn(i, 0, n){
        ans+=l[i];
    }
    
    forn(i, 0, k-1){
        ans+=r[i];
    }
    ans++;

    cout << ans << nl;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}