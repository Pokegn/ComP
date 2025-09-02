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
    lli n,m,k; cin >> n >> m >>k;
    string s; cin >> s;
    lli pos = -1;
    lli w = 0;
    lli dest;

    dest = -1;
    forn(i, 1, m+1){
        if(s[pos+i] == 'L') dest = pos+i;
    }
    if(dest == -1) dest = pos+m;
    pos = dest;


    while(pos < n){
        if(s[pos] == 'W'){
            w++;
            pos++;
            continue;
        }
        if(s[pos] == 'L'){
            dest = -1;
            forn(i, 1, m+1){
                if(s[pos+i] == 'L') dest = pos+i;
            }
            if(dest == -1) dest = pos+m;
            pos = dest;
            continue;
        }
        if(s[pos] == 'C'){
            cout << "NO" << nl;
            return;
        }
    }
    if(w>k) cout << "NO"<< nl;
    else{
        cout << "YES" << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}