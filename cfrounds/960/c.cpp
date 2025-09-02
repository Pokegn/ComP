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
    vlli a(n);
    forn(i,0, n) cin >> a[i];  
    lli sum = 0;
    forn(i, 0, n) sum+=a[i];
    //cout << sum << ' ';
    lli mad = 0;
    vector<bool> vis(n+1, 0);
    vlli niu(n);
    forn(i, 0, n){
        if(vis[a[i]] == 1){
            mad = max(mad, a[i]);
        }
        vis[a[i]] = 1;
        niu[i] = mad;
    }
    forn(i, 0, n) sum+=niu[i];
    //cout << sum << ' ';
    //forn(i, 0, n) cout << niu[i] << ' ';

    mad = 0;
    forn(i, 0, n+1) vis[i] = false;
    forn(i, 0, n){
        if(vis[niu[i]] == 1){
            mad = max(mad, niu[i]);
            //cout << "xd";
        }
        vis[niu[i]] = 1;
        niu[i] = mad;
        //cout << niu[i] << ' ';
    }

    //cout << nl;
    forn(i, 0, n){
        sum+=niu[i]*(n-i);
    }

    cout << sum << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}