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
#define MOD 998244353

void solve(){
    lli n; cin >> n;
    vlli a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    vvlli ans(n, vlli(3001, 0));
    forn(i, 0, n){
        if(i == 0){
            forn(j, a[i], b[i]+1){
                ans[i][j] = 1;
            }
            continue;
        }
        forn(j, a[i-1], b[i-1]+1){
            if(j<= a[i]) ans[i][a[i]] += ans[i-1][j];
        }
        forn(j, a[i]+1, b[i]+1){
            ans[i][j] = ans[i-1][j] + ans[i][j-1];
            ans[i][j] %= MOD;
        }
    }
    lli anss = 0;

    //cout << ans[0][0] << " " << ans[0][1] << " " << ans[0][2] << " " << ans[0][3] << " " << ans[0][4] << " " << ans[0][5] << nl;
    //cout << ans[1][0] << " " << ans[1][1] << " " << ans[1][2] << " " << ans[1][3] << " " << ans[1][4] << " " << ans[1][5] << nl;


    forn(i, 0, 3001){
        anss+=ans[n-1][i];
        anss %= MOD;
    }
    cout << anss%MOD << nl;
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}