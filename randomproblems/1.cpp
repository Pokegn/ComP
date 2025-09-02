//https://codeforces.com/contest/575/problem/D
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
    cout << 2000 << nl;
    forn(i, 1, 1001){
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << nl;
    }
    forn(i, 1, 1001){
        cout << 1001-i << ' ' << 1 << ' ' << 1001-i << ' ' << 2 << nl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    while(t--) solve();
    return 0;
}