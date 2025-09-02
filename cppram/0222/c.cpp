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
    lli t; cin >> t;
    lli k,p,n;
    while(t--){
        cin >> k >> p >> n;
        if(p>=k){
            cout << 0 << nl;
            continue;
        }
        else{
            cout << n*(k-p) << nl;
            continue;
        }
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}