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
typedef vector<long long> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n,m; cin >> n >> m;
    vi a(n); rep(i, 0, n) cin >> a[i];
    if(m == 1){
        ll maxi = a[0];
        rep(i, 0, n) maxi =max(maxi, a[i]);
        cout << maxi << endl;
        return;
    }
    ll sneg = 0;
    priority_queue<ll> pq;
    rep(i, 0, m-1){ //quiero tener los m-1 mas chicos
        pq.push(a[i]);
        sneg+=a[i];
    }
    ll ans = m*a[m-1] - sneg;
    rep(i, m-1, n){
        ans = max(ans, m*a[i]-sneg);
        if(a[i]<pq.top()){
            ll topo = pq.top();
            pq.pop();
            pq.push(a[i]);
            sneg = sneg + a[i] - topo;
        }
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}