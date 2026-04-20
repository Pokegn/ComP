//https://codeforces.com/contest/575/problem/F

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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ll cost(ll x, ll l, ll r){
    ll diff1, diff2;
    diff1 = abs(x-l);
    diff2 = abs(x-r);
    return min(diff1, diff2);
}

void solve(){
    ll n; cin >> n;
    ll x; cin >> x;
    vector<pair<ll, ll>> a(n+1, {0,0}); rep(i,1, n+1) cin >> a[i].fi >> a[i].se; //a tiene las parejas bien
    // minheap<ll> xd; rep(i, 0, n){
    //     xd.push(a[i].fi), xd.push(a[i].se);
    // }
    // map<ll, ll> m; //del numero a indice
    vector<ll> mr;
    rep(i, 1, n+1){
        mr.push_back(a[i].fi); mr.push_back(a[i].se);
    }
    mr.push_back(x);
    sort(all(mr));

    vector<vector<ll>> dp(n+1, vector<ll>(2*n+1, 1e14)); //dp[i][j] es en el paso i, que pasa si lo pones en j
    rep(j, 0, 2*n+1) if(mr[j] == x) dp[0][j] = 0;

    rep(i, 1, n+1){
        rep(j, 0, 2*n+1){
            dp[i][j] = dp[i-1][j]; //estatico...
        }
        vector<ll> bestder(2*n+1, 1e14), bestizq(2*n+1, 1e14);
        //me muevo a la derecha...
        ll bestval = dp[i-1][0]; //mejor val de donde estaba antes
        ll bestvalpos = mr[0];
        for(int j = 1; j<(2*n+1); j++){ //costidx es el costo de moverlo de idx a j, costcurr es el costo de moverlo de j a j
            bestder[j] = bestval + abs(bestvalpos - mr[j]);
            if(dp[i][j] < bestder[j]){
                bestval = dp[i][j];
                bestvalpos = mr[j];
                bestder[j] = dp[i][j];
            }
        }

        //o me muevo a la izquierda
        bestval = dp[i-1][2*n]; //mejor val de donde estaba antes
        bestvalpos = mr[2*n];
        for(int j = 2*n-1; j>=0; j--){
            bestizq[j] = bestval + abs(bestvalpos - mr[j]);
            if(dp[i][j] < bestizq[j]){
                bestval = dp[i][j];
                bestvalpos = mr[j];
                bestizq[j] = dp[i][j];
            }
        }

        rep(j, 0, 2*n+1){
            dp[i][j] = min(dp[i][j], bestder[j]);
            dp[i][j] = min(dp[i][j], bestizq[j]);
            dp[i][j] += cost(mr[j], a[i].fi, a[i].se);
        }
    }

    ll ans = (1e18);
    rep(j, 0, 2*n+1){
        ans = min(dp[n][j], ans);
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