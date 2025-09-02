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
    string s; cin >> s;
    int sz = s.length();
    int xd = -1;
    forn(i, 1, sz){
        if(s[i] == s[i-1]) xd = i;
    }

    string r;
    if(xd!=-1){
        forn(i, 0, xd){
            r+=s[i];
        }
        r+=(s[xd] == 'a' ? 'b':'a');
        forn(i, xd, sz) r+=s[i];
    }
    else{
        r+=(s[0] == 'a' ? 'b':'a');
        forn(i, 0, sz) r+=s[i];
    }
    cout << r << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}