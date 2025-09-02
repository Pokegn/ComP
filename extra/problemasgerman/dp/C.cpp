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
    vvlli vals(n, vlli(3));
    forn(i, 0, n){
        cin >> vals[i][0] >> vals[i][1] >> vals[i][2];
    }

    vvlli ans(n, vlli(3));
    ans[0][0] = vals[0][0];
    ans[0][1] = vals[0][1];
    ans[0][2] = vals[0][2];

    forn(i, 1, n){
        ans[i][0] = max(ans[i-1][1] + vals[i][0], ans[i-1][2] + vals[i][0]);
        ans[i][1] = max(ans[i-1][0] + vals[i][1], ans[i-1][2] + vals[i][1]);
        ans[i][2] = max(ans[i-1][0] + vals[i][2], ans[i-1][1] + vals[i][2]);
    }
    cout << max(ans[n-1][0], max(ans[n-1][1], ans[n-1][2])) << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}