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
#define MOD 1000000007

string s;
vvlli ans;
vector<vector<bool>> vis;
vlli sumrango;
lli res(lli l, lli r){
    if(vis[l][r]) return ans[l][r];
    if(l>r) return 1;
    //cout << l << ' ' << r << nl;
    vis[l][r] = 1;
    ans[l][r] = 1; //cuando agarro todo
    forn(i, l, r){
        forn(j, i+1, r+1){
            if(sumrango[i+1]-sumrango[l] == sumrango[r+1]-sumrango[j]){  
                ans[l][r] += res(i+1, j-1);
            }
        }
    }
    ans[l][r]%=MOD;
    return ans[l][r];
}

void solve(){
    cin >> s;
    lli len = s.length();
    ans.assign(len, vlli(len, 0));
    vis.assign(len, vector<bool> (len, false));
    sumrango.assign(len+1, 0);
    forn(i, 1, len+1){
        sumrango[i] = sumrango[i-1] + (s[i-1]-'0'); //sumarango[i] es suma desde 0 hasta i-1
    }
    
    cout << res(0, len-1)%MOD << nl;

    // forn(i, 0, len){
    //     forn(j, i, len){
    //         cout << i << ' ' << j << ' ' << ans[i][j] << nl;
    //     }
    // }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}