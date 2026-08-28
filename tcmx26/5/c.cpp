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

ll dp[200][200][200];

void solve(){
    int R,G,B; cin >> R >> G >> B;
    vi r(R), g(G), b(B);
    rep(i, 0, R) cin >> r[i];
    rep(i, 0, G) cin >> g[i];
    rep(i, 0, B) cin >> b[i];

    sort(all(r), greater<int>());
    sort(all(g), greater<int>());
    sort(all(b), greater<int>());

    ll ans = 0;

    rep(t1, 0, 200){ //rg
        rep(t2, 0, 200){ //rb
            rep(t3, 0, 200){
                int r_rem = R-t1-t2;
                int g_rem = G-t1-t3;
                int b_rem = B-t2-t3;
                if(r_rem < 0 || g_rem < 0 || b_rem < 0) continue;

                if(t1 > 0) dp[t1][t2][t3] = max(dp[t1][t2][t3], dp[t1-1][t2][t3] + r[t1-1+t2]*g[t1-1+t3]);
                if(t2 > 0) dp[t1][t2][t3] = max(dp[t1][t2][t3], dp[t1][t2-1][t3] + r[t1+t2-1]*b[t2-1+t3]);
                if(t3 > 0) dp[t1][t2][t3] = max(dp[t1][t2][t3], dp[t1][t2][t3-1] + g[t1+t3-1]*b[t2+t3-1]);

                ans = max(ans, dp[t1][t2][t3]);
            }
        }
    }
    
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}