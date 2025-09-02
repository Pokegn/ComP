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
    lli n, k; cin >> n >> k;
    vlli a(n); forn(i, 0, n) cin >>a[i];
    vlli mods(k, 0);
    forn(i, 0, n) mods[a[i]%k] ++;
    string ans = "NO";
    lli index = -1;
    forn(i, 0, n) if(mods[a[i]%k] == 1){
        index = i;
        ans = "YES";
    } 
    cout << ans << nl;
    if(ans == "YES") cout << index+1 << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}