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
    forn(i, 0, n) cin >> a[i];
    forn(i, 1, n){
        if(a[i]%2 != a[0]%2){
            cout << -1 << nl;
            return;
        }
    }

    int xd = 30;
    if(a[0]%2 ==0) xd++;

    cout << xd << nl;
    lli x = 1;
    forn(i, 0, 29) x*=2;
    forn(i, 0, xd){
        if(x==0){
            cout << 1 << ' ';
            continue;
        }
        cout << x << ' ';
        x/=2;
    }
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}