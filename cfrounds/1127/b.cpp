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
    ll n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];

    vector<ll> neg(n), pos(n); //valores de s pa ambos lados

    ll s = a[0];
    neg[0] = pos[0] = a[0];
    rep(i, 1, n){
        neg[i] = min({a[i], neg[i-1]+a[i], 2*neg[i-1]+a[i]});
        pos[i] = max({a[i], pos[i-1]+a[i], 2*pos[i-1]+a[i]});
    }

    ll ans = a[0];
    rep(i, 1, n){
        ans = max({ans, a[i]-neg[i-1], a[i]+pos[i-1]});
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}