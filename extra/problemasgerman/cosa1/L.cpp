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
    if(n<10){
        cout << n << nl;
        return;
    }
    if(n == 11){
        cout << 4 << nl; return;
    } 
    if(n == 13){
        cout << 5 << nl;
    } 
    if(n%2 == 0){
        cout << ((lli)(n/2)%MOD) << nl;
        return;
    }
    if(n<=27){
        cout << 9 << nl;
        return;
    }
    cout << ((lli)(n-11)/2 + 1)%MOD << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}