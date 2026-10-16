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
    ll n, k; cin >> n >> k;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];

    vector<ll> cum = a;
    rep(i, 1, n){
        cum[i] += cum[i-1];
    }

    vector<vector<ll>> b(k);
    b[0].push_back(0);
    rep(i, 0, n){
            b[cum[i]%k].push_back(i+1);
    }

    ll ans = 0;
    rep(i, 0, k){
        ll siz = sz(b[i]);
        if(siz == 0) continue;
        // cout << i << ' ' << siz << endl;
        ll l = 0, r = 0;
        while(r < siz){
            if(l == r){
                r++; continue;
            }
            if(b[i][r] - b[i][l] <= k){ // de l+1 a r, el tamano es r-l
                r++; continue;
            }
            ans += (siz-1 - r + 1);
            l++;
        }
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