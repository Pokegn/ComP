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
    lli n; cin >> n;
    vlli a(n);
    forn(i, 0, n ) cin >> a[i];
    sort(a.begin(), a.end());
    lli ind = -1;
    forn(i, 1, n){
        if(a[i-1] == a[i]) ind = i;
    }
    if(ind == -1){
        cout << -1 << nl;
    }
    else{
        vlli b(0);
        lli x, y;
        forn(i, 0, n){
            if(i!=ind && i!=ind-1) b.pb(a[i]);
        }
        lli dif = 1e9;
        forn(i, 1, n-2){
            if(b[i]-b[i-1] < dif){
                dif = min(dif, b[i]-b[i-1]);
                x = b[i];
                y = b[i-1]; 
            }
        }

        if(dif>=2*a[ind]){
            cout << -1 << nl;
        }
        else{
            cout << a[ind] << ' ' << a[ind-1] << ' ' << x << ' ' << y << nl;
        }
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}