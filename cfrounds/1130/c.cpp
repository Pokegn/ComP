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
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll l = 1, r = 1e9+1;

    vector<ll> reach(n);
    reach[0] = a[1]-a[0];
    reach[n-1] = a[n-1]-a[n-2];
    rep(i, 1, n-1){
        reach[i] = min(a[i]-a[i-1], a[i+1]-a[i]);
    }

    while(l < r){
        ll m = (l+r)/2;
        vector<bool> need(n, false);
        rep(i, 0, n){
            if(reach[i] > m) need[i] = true;
        }

        int y = 0;

        rep(i, 0, n){
            if(need[i]){
                y++;
                if(i < n-1 && a[i+1] - a[i] <= 2*m) need[i+1] = false;
            }
        }

        if(y <= x){
            r = m;
        }
        else{
            l = m+1;
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