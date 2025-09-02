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
    vlli cansum(100001, 0);
    cansum[0] = 1;
    vlli t(n);
    forn(i, 0, n) cin >> t[i];
    
    forn(i, 0, n){
        rof(j, 100000, 0){
            if(cansum[j] == 1) cansum[j+t[i]] = 1;
        }
    }

    lli totalsum = 0;
    forn(i, 0, n) totalsum+=t[i];

    lli maxsum = 0;
    forn(i, 0, totalsum/2 +1){
        if(cansum[i]) maxsum = i;
    }

    cout << totalsum - maxsum << nl;
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
