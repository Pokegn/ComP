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
    ll t; cin >> t;
    vector<ll> a(n); rep(i,0,n) cin >> a[i];

    ll l = 1, r = 1e18;
    while(l < r){
        ll m = l + (r-l)/2;

        ll build = 0;
        rep(i,0,n) build += m/a[i];
        if(build >= t){
            r = m;
        }
        else l = m+1;
    }
    cout << l << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}