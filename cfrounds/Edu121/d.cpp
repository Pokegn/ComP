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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    
    vector<int> freq(n+1, 0);
    rep(i, 0, n) freq[a[i]]++;

    rep(i, 1, n+1) freq[i]+=freq[i-1]; //hay x menores o iguales a i

    ll ans = 1e17;
    rep(i, 0, 19) 
    rep(j, 0, 19) rep(k, 0, 19)
    { //voy a tener 2^i, 2^j, 2^k en cada seccion
        int idx1 = upper_bound(freq.begin(), freq.end(), (1<<i))-freq.begin();
        int idx2 = upper_bound(all(freq), (freq[idx1-1] + (1<<j))) - freq.begin();
        
        ll g1, g2, g3;
        g1 = freq[idx1-1];
        g2 = freq[idx2-1] - g1;
        g3 = freq[n] - g1 - g2;
        ll add[4];
        add[1] = (1<<i) - g1;
        add[2] = (1<<j) - g2;
        add[3] = (1<<k) - g3;
        if(add[1] < 0 || add[2] < 0 || add[3] < 0) continue;
        
        ans = min(ans, add[1] + add[2] + add[3]);

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