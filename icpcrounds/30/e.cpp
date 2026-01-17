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
//#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll exp;
    ll n; cin >> n;
    ll pot;
    ll ni;
    cout << 0 << ' ' << 0 << endl;
    string s0, s;
    cin >> s0;
    ll color = 0; //black 0 white 1
    ni = n/2;
    exp = 20;
    pot = 1<<20;
    ll l,r;
    l = 0;
    r = 1e9;
    ll m;
    for(ll i=0; i<ni; i++){
        m = (l+r)/2;
        cout << 0 << ' ' << m << endl;
        cin >> s;
        if(s == s0){
            l = m;
        }
        else r = m;
    }
    ll y = (l+r)/2;

    l = 0;
    r = 1e9;
    for(ll i=0; i<(n-ni-1); i++){
        m = (l+r)/2;
        cout << m << ' ' << 0 << endl;
        cin >> s;
        if(s == s0){
            l = m;
        }
        else r = m;
    }
    ll x = (l+r)/2;

    cout << 0 << ' ' << y << ' ' << x << ' ' << 0 << endl;
    return;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}