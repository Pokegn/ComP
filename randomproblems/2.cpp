// https://codeforces.com/contest/67/problem/A

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
    lli n; cin >> n;
    vlli left(n);
    vlli right(n);
    string s; cin >> s;
    left[n-1] = 1;
    right[0] = 1;
    forn(i,0 ,n-1){
        if(s[i] == 'L'){
            right[i+1] = 1;
        }
        if(s[i] == 'R'){
            right[i+1] = right[i]+1;
        }
        if(s[i] == '='){
            right[i+1] = right[i];            
        }
    }
    rof(i, n-1, 1){
        if(s[i-1] == 'R'){
            left[i-1] = 1;
        }
        if(s[i-1] == 'L'){
            left[i-1] = left[i]+1;
        }
        if(s[i-1] == '='){
            left[i-1] = left[i];            
        }
    }
    vlli ans(n);
    forn(i, 0, n){
        ans[i] = max(left[i], right[i]);
    }
    forn(i, 0, n) cout << ans[i] << ' ';
    cout << nl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}