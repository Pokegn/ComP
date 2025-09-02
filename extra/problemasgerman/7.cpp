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
#define f first
#define s second
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, m; cin >> n >> m;
    vlli a(n); forn(i, 0, n) cin >> a[i];

    vlli maxventa(n, 0);
    lli ans = -1e18;

    lli x, y;
    vector<pair<lli, lli>> pares;
    forn(i, 0, m){
        cin >> x>>y;
        pares.push_back({y-1, x-1});
    }

    sort(pares.begin(), pares.end(), greater<pair<lli, lli>>());

    forn(i, 0, m){
        maxventa[pares[i].s] = max(maxventa[pares[i].s], max(maxventa[pares[i].f], a[pares[i].f]));
    }

    forn(i, 0, n){
        if(maxventa[i] > 0)
        ans = max(ans, maxventa[i] - a[i]);
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}