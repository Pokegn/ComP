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
    k--;
    lli lastk = 1e10;
    lli pot = 1;
    vlli dir(n+1); //0 left 1 right
    dir[n] = 0;
    rof(i, n-1, 1){
        if(k%2 == 1) dir[i] = 1;
        else dir[i] = 0;
        if(i == 1) lastk = k;
        k/=2;
    }
    vlli lefts(0);
    vlli rights(0);

    if(k > 0){
        cout << -1 << nl;
        return;
    }

    forn(i, 1, n+1){
        if(dir[i] == 0){
            lefts.push_back(i);
        }
        else rights.push_back(i);
    }

    lli lsz = lefts.size();
    lli rsz = rights.size();

    forn(i, 0, lsz){
        cout << lefts[i] << ' ';
    }
    rof(i, rsz-1, 0) cout << rights[i] << ' ';
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}