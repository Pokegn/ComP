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
#define MOD 676767677

void solve(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    ll unos = 0;
    ll ans = 0;
    rep(i, 0, n){
        if(a[i] == 1) unos++;
        else ans+=a[i];
    }
    if(unos>0){
        if(unos == n){
            cout << 1 << endl;
            return;
        }
        else{
            if(a[n-1] == 1) cout << ans+1 << endl;
            else cout << ans << endl;
            return;
        } 
    }
    else{
        cout << ans << endl;
        return;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}