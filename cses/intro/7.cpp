#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n; cin >> n;
    vlli ans = {0,0,
6,
28,
96,
252,
550};
    ll ts = 0;
    for(ll i=7; i<=n; i++){
        ts = ans[i-1];
        ts += -4*(2*i-1)+14;
        ts += ((i-1)*(2*i-1)-2)+(2*i-1)*(i-1)*(i-1);
        ans.push_back(ts);
    }

    for(ll i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
    return;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}