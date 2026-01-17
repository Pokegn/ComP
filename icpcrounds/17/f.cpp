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
    ll n,k; cin >> n >> k;
    vlli a(n); for(int i=0; i<n; i++) cin >> a[i];
    vlli b, c;
    for(int i=0; i<n; i++){
        ll x = a[i];
        if(x<0){
            c.push_back(-x);
        } 
        else b.push_back(x);
    }

    sort(b.begin(), b.end());
    ll curr = b.size()-1;
    ll ans = 0;
    while(curr>=0){
        ans+=2*b[curr];
        curr-=k;
    }
    
    sort(c.begin(), c.end());
    curr = c.size()-1;
    while(curr>=0){
        ans+=2*c[curr];
        curr-=k;
    }
    ll resta = -1;
    if(c.size()>0) resta = c[c.size()-1];
    if(b.size()>0) resta = max(resta, b[b.size()-1]);
    ans-=resta;


    cout << ans << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}