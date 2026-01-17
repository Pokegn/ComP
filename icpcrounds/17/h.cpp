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
    ll  n,m,k; cin >> n >> m >> k;
    if(k>=m) k=m-1;
    vlli a(n); for(int i=0; i<n; i++) cin >> a[i];
    vlli lefts(n);
    for(int i=0; i<m; i++){
        lefts[i] = max(a[i], a[n-1-(m-1)+i]);
    }

    ll ans = -1;

    for(int forcedlefts = 0; forcedlefts <= k; forcedlefts++){
        int forcedrights = k-forcedlefts;
        ll secure = 1e10;
        for(int x = forcedlefts; x<m-forcedrights; x++){
            secure = min(secure, lefts[x]);
        }
        ans = max(ans, secure);
    }

    cout << ans << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}