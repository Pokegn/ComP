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
    lli k, l1, l2, r1, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    lli pot = 1;
    lli ans = 0;
    lli mini, maxi;
    while(pot <= r2){
        lli ceili = l2/pot;
        if(l2%pot != 0) ceili++;
        mini = max(l1, ceili);
        maxi = min(r1, (lli)(r2/pot));

        if(maxi-mini >= 0) ans+=maxi-mini+1;
        pot*=k;
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}