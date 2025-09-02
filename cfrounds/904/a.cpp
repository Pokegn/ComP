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

lli sumd(lli n){
    lli sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void solve(){
    lli x, k; cin >> x >> k;
    lli s = sumd(x);
    lli xd = x;
    while(s%k!=0){
        xd++;
        s = sumd(xd);
    }
    cout << xd << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}