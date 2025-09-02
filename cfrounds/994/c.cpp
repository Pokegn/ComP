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
    lli n, x, y; cin >> n >> x >> y;
    if(x>y) swap(x, y);
    vlli a(n+1);
    a[1] = 0;
    forn(i, 2, n){ // el x, el y, el 1 y el n
        if(i!=y){
            if(a[i-1]!=0) a[i] = 0;
            else a[i] = 1;
        }
        else{
            a[i] = 0;
            if(a[x] == 0 || a[i-1] == 0){
                if(a[x] == 1 || a[i-1] == 1) a[i] = 2;
                else a[i] = 1;
            }
        }
    }
    a[n] = 1;
    if(n == y){
        if(a[x] == 1 || a[n-1] == 1){
            if(a[x] == 2 || a[n-1] == 2) a[n] = 3;
            else a[n] = 2;
        } 
    }
    else{
        if(a[n-1] == 1) a[n] = 2;
    }

    forn(i, 1, n+1) cout << a[i] << ' ';
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}