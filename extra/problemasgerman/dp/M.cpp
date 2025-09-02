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

vlli a;
vvlli sans;

void solve(){
    lli n, k; cin >> n >> k;
    a.assign(n+1, 0);
    sans.assign(n+1, vlli(k+1, 0));


    forn(i, 1, n+1) cin >> a[i];

    forn(j, 0, a[1]+1){
        sans[1][j] = j+1;
    }
    forn(j, a[1]+1, k+1){
        sans[1][j] = sans[1][a[1]];
    }

    forn(i, 2, n+1){
        forn(j, 0, k+1){
            if(j>0) sans[i][j] += sans[i][j-1];

            sans[i][j] += sans[i-1][j];
            if(j-a[i]>0) sans[i][j] -= sans[i-1][j-a[i]-1];
            sans[i][j] = sans[i][j]%MOD;
        }
    }

    // forn(i, 1, n+1){
    //     forn(j, 0, k+1){
    //         cout << sans[i][j] << ' ';
    //     }
    //     cout << nl;
    // }

    if(k == 0) cout <<(sans[n][k]+MOD)%MOD << nl;
    else cout << (sans[n][k] - sans[n][k-1]+MOD)%MOD << nl; 

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}