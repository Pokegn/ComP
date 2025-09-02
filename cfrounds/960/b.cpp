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
    lli n,x,y; cin >> n >> x>> y;
    forn(i, 1, y){
        if(i%2 == y%2){
            cout << 1 << ' ';
        }
        else cout << -1 << ' ';
    }
    forn(i, y, x+1){
        cout << 1 << ' ';

    }
    forn(i, x+1, n+1){
        if(i%2 == (x+1)%2){
            cout << -1 << ' ';
        
        }
        else cout << 1 << ' ';
    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}