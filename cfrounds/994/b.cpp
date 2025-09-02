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
    int n; cin >> n;
    string st; cin >> st;
    bool p = false;
    bool s = false;
    forn(i, 0, n){
        if(st[i] == 'p') p = true;
        if(st[i] == 's') s = true;
    }
    if(p&&s){
        bool midp = false;
        bool mids = false;
        if(st[0] == 'p') midp = true;
        if(st[n-1] == 's') mids = true;
        forn(i, 1, n-1){
            if(st[i] == 'p') midp = true;
            if(st[i] == 's') mids = true;
        }
        if(mids && midp) cout << "NO" << nl;
        else cout << "YES" << nl;
    }
    else{
        cout << "yES" << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}