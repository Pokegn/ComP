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
    lli n, m, k; cin >> n >> m >> k;
    vvlli a(n+1, vlli(m, 0));
    forn(i, 1, n+1){
        forn(j, 0, m){
            cin >> a[i][j];
        }
    }

    vvlli ans(n+1, vlli(m, 1e18));
    vector<vvlli> sans(n+1, vvlli(m, vlli(m, 1e18)));

    ans[0][0] = 0;
    forn(i, 0, m){
        forn(j, 0, m){
            sans[0][i][j] = k*j;
        }
    }

    forn(i, 1, n+1){
        forn(j, 0, m){
            forn(p, 0, m){
                sans[i][j][p] = min(ans[i-1][j]+k*p, sans[i][(j-1+m)%m][p]) + a[i][(j+p)%m];
                ans[i][j] = min(ans[i][j], sans[i][j][p]);
            }
        }
    }

    // forn(i, 0, n+1){
    //     forn(j, 0, m){
    //         cout << ans[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    cout << ans[n][m-1] << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}