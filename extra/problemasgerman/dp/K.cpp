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

vlli ans(1000000, 0);
vlli a;
lli n;
lli xd = 0;

void fill_(lli i){
    xd++;
    if(ans[i]!=0) return;
    ans[i] = -1;
    forn(j, 0, n){
        xd++;
        if(i-a[j] >= 0){
            fill_(i-a[j]);
            if(ans[i-a[j]] == -1) ans[i] = 1;
        }
    }
}

void solve(){
    lli k; cin >> n >> k;
    a.assign(n, 0);
    forn(i, 0, n) cin >> a[i];

    ans[0] = -1;
    fill_(k);
    if(ans[k] == 1) cout << "First" << nl;
    else cout << "Second" << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}