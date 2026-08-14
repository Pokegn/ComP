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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> reps(n+1, 0);
    rep(i, 0, n) reps[a[i]]++;
    ll ans = 0;
    ll x,y,z;
    rep(i, 1, n+1){
        x = reps[i];
        //el mismo
        ans += (x*(x-1)*(x-2))/6;
        if(i+1 <= n){
            y = reps[i+1];
            ans += (x*(x-1)*y)/2;
            ans += (x*y*(y-1))/2;
        }
        if(i+2 <= n){
            z = reps[i+2];
            ans += (x*(x-1)*z)/2;
            ans += (x*z*(z-1))/2;
            ans += (x*y*z);
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