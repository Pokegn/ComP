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
    int n, m, x; cin >> n >> m >> x;
    vi c(n); 
    vvi a(n, vi(m));
    forn(i, 0, n){
        cin >> c[i];
        forn(j, 0, m){
            cin >> a[i][j];
        }
    }

    lli maxi = 1<<n;
    vlli sum(m);
    lli mincost = 1e11;
    lli bigsum;
    lli xd;
    forn(i, 0, maxi){
        xd = i;
        forn(j, 0, m) sum[j] = 0;
        bigsum = 0;

        forn(j, 0, n){
            if(xd%2 == 1){
                bigsum += c[j];
                forn(k, 0, m) sum[k]+=a[j][k];
            }
            xd/=2;
        }

        forn(j, 0, m) if(sum[j] < x) bigsum = 1e11;
        mincost = min(mincost, bigsum);
    }

    if(mincost == 1e11) cout << -1 << nl;
    else cout << mincost << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}