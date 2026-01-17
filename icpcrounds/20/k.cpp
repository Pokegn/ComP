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
    vlli a,b,c,d;
    ll ci;
    a.push_back(0);
    d.push_back(0);
    c.push_back(0);
    b.push_back(0);
    for(int i=0; i<n; i++){
        cin >> ci; a.push_back(ci);
        cin >> ci; b.push_back(ci);
        cin >> ci; c.push_back(ci);
        cin >> ci; d.push_back(ci);
    }
    
    vector<bool> precario(n+1, false);

    for(int i=1; i<=n; i++){
        if(a[i]*d[i] == b[i]*c[i]) precario[i] = true;
    }

    vlli acomp(n+1);
    vlli bcomp(n+1);
    vlli ccomp(n+1);
    vlli dcomp(n+1);

    acomp[0] = 1;
    bcomp[0] = 0;
    ccomp[0] = 0;
    dcomp[0] = 1;

    for(int i=0; i<=n; i++){
        if(precario[i]) continue;
        
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}