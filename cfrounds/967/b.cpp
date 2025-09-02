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
    if(n%2==0){
        cout << -1 << nl;
        return;
    }
    if(n==1){
        cout << 1 << nl;
        return;
    }

    map<lli ,lli> sig;
    map<lli, lli> prev;
    sig[1] = 3;
    sig[2] = -1;
    prev[2] = 3;
    prev[1] = -1;
    sig[3] = 2;
    prev[3] = 1;

    for(lli i=4; i<n+1; i+=2){
        prev[i] = prev[i-1];
        sig[i+1] = sig[i-1];

        sig[prev[i-1]] = i;
        prev[i-1] = i;
        prev[sig[i-1]] = i+1;
        sig[i-1] = i+1;

        sig[i] = i-1;
        prev[i+1] = i-1;

    }

    cout << 1 << ' ';
    lli x = sig[1];
    forn(i, 1, n){
        cout << x << ' ';
        x = sig[x];
    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}