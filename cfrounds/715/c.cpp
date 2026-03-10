#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vector<ll> a(n); rep(i,0 , n) cin>> a[i];
    sort(all(a));

    vector<vector<ll>> maxi(n, vector<ll>(n));
    vector<vector<ll>> mini(n, vector<ll>(n));

    rep(i, 0, n){
        rep(j, i, n){
            if(i==j){
                maxi[i][j] = a[i];
                mini[i][j] = a[i];
                continue;
            }
            maxi[i][j] = max(maxi[i][j-1], a[j]);
            mini[i][j] = min(mini[i][j-1], a[j]);
        }
    }

    //cout << "xd " << maxi[0][2] << ' ' << mini[0][2] << endl;

    ll ans[n][n];
    rep(add, 0, n){
        rep(i, 0, n){
            if(i+add > n-1) continue;
            if(add == 0){
                ans[i][i+add] = 0;
                continue;
            } 
            ans[i][i+add] = min(ans[i][i+add-1], ans[i+1][i+add]);
            ans[i][i+add] += maxi[i][i+add]-mini[i][i+add];
        }
    }

    // rep(i, 0, n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, n){
    //     rep(j, 0, i) cout << 0 << ' ';
    //     rep(j, i, n){
    //         cout << ans[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << ans[0][n-1] << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
   // cin >> t;
    while(t--) solve();
    return 0;
}