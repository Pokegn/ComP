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
#define MOD 1000000007

void solve(){
    lli n; cin >> n;
    lli m; cin >> m;
    vlli a(m); forn(i, 0, m) cin >> a[i];

    vlli ans(n+1, 0);

    ans[0] = 1;
    lli j = 0;
    forn(i, 1, n+1){
        if(j<m && i == a[j]){
            ans[i] = 0;
            j++;
            continue;
        }

        else{
            ans[i] += ans[i-1];
            if(i>1) ans[i] += ans[i-2];
            ans[i] = ans[i]%MOD;
        }
    }

    cout << ans[n]%MOD << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}