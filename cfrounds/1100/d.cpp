#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i,0,n) cin >> a[i]; 
    rep(i,0,n) cin >> b[i]; 

    ll l = 0, r = 2*n;
    while(l<r){
        ll m = (l+r+1)/2;
        vector<ll> c(n, 0);
        rep(i, 0, n) if(a[i] >= m) c[i]++;
        rep(i, 0, n) if(b[i] >= m) c[i]++;
        vector<ll> d;
        rep(i, 0, n){
            if(c[i] == 1) continue;
            if(c[i] == 0){
                if(d.size() == 0 || d.back() != 0) d.push_back(0);
            }
            if(c[i] == 2) d.push_back(2);
        }
        ll suma = 0;
        for(auto x: d) suma+=x;
        int sz = d.size();
        if(suma-(sz-1) >= 2){
            l = m;
        }
        else{
            r = m-1;
        }
    }
    cout << l << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}