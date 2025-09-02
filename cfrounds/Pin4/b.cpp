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
    vlli b(n); forn(i, 1,  n) cin >> b[i];
    vlli a(n+1);

    forn(i, 1, n+1){
        if(i == 1) a[i] = b[i];
        else if(i == n) a[i] = b[i-1];
        else{
            a[i] = (b[i-1]|b[i]);
        }
    }

    forn(i, 1, n){
        if((a[i]&a[i+1]) != b[i]){
            cout << -1 << nl;
            return;
        }
    }
    
    forn(i, 1, n+1){
        cout << a[i] << ' ';
    }
    cout << nl;
    return;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}