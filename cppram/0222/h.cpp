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
    lli n, k; cin >> n >> k;
    vlli p(3);
    vlli a(0);
    forn(i, 0, n){
        cin >> p[0] >> p[1] >> p[2];
        sort(p.begin(), p.end());
        a.pb(p[0]);
        a.pb(p[1]);
    }

    sort(a.begin(), a.end());
    lli ans =0 ;
    forn(i, 0, k){
        ans+=a[i];
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    lli t; cin >> t;
    while(t--)
    solve();
    return 0;
}