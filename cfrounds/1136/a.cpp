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

vector<ll> cum;

void solve(){
    ll n; cin >> n;
    ll x = 1;
    while(x*(x+1)/2 < n) x++;
    ll ans = x+x-1; //llego minimo a x
    rep(i, x, n+1){
        ll sobra = i*(i+1)/2 - n;
        ll moves = i-1;
        ll extra = i - (upper_bound(all(cum), sobra) - 1 - cum.begin());
        moves += extra;
        ans = min(ans, moves);
    }
    cout << ans << endl;
}


int main(){

    cin.tie(0)->sync_with_stdio(false);
    cum.resize(1002);
    rep(i, 0, 1002){
        cum[i] = i*(i+1)/2;
    }
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}