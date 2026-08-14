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
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    ll dp[n];
    ll sobra[n];

    dp[0] = a[0];
    sobra[0] = 0;

    rep(i, 1, n){
        // if(a[i] >= dp[i-1]){
        //     dp[i] = dp[i-1];
        //     sobra[i] = sobra[i-1] + a[i]-dp[i-1];
        // }
        // else{ //le quito a sobra
            int l = 0, r = dp[i-1];
            while(l < r){
                ll m = (l+r+1)/2;
                if(sobra[i-1] + a[i] + i*(dp[i-1] - m) >= m){ // si se puede
                    l = m;
                }
                else{
                    r = m-1;
                }
            }
            sobra[i] = a[i] + sobra[i-1] + i*(dp[i-1] - l) - l;
            dp[i] = l;
        //}
    }
    rep(i, 0, n) cout << dp[i] << ' ';
    cout << endl;
    // rep(i, 0, n) cout << sobra[i] << ' ';
    // cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}