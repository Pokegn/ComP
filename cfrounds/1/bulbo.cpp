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

    vector<ll> mrmalo;
    rep(i, 1, n+1){
        mrmalo.push_back(a[i].fi); mrmalo.push_back(a[i].se);
    }
    mrmalo.push_back(x);
    sort(all(mrmalo));

    vector<ll> mr; mr.push_back(mrmalo[0]);
    for(int i=1; i<mrmalo.size(); i++){
        if(mrmalo[i] != mrmalo[i-1]) mr.push_back(mrmalo[i]);
    }
    int sz = mr.size();


    //vector<vector<ll>> dp(n+1, vector<ll>(sz, 1e18)); //dp[i][j] es en el paso i, que pasa si lo pones en j
    vector<ll> pdp(sz, 1e18), dp(sz, 1e18);
    rep(j, 0, sz) if(mr[j] == x) pdp[j] = 0;

    rep(i, 1, n+1){
        dp = vector<ll> (sz, 1e18);
        rep(j, 0, sz){
            dp[j] = pdp[j]; //estatico...
        }
        vector<ll> bestder(sz, 1e18), bestizq(sz, 1e18);
        //me muevo a la derecha...
        ll bestval = pdp[0]; //mejor val de donde estaba antes
        ll bestvalpos = mr[0];
        for(int j = 0; j<(sz); j++){ //costidx es el costo de moverlo de idx a j, costcurr es el costo de moverlo de j a j
            bestder[j] = bestval + mr[j] - bestvalpos;
            if(dp[j] < bestder[j]){
                bestval = dp[j];
                bestvalpos = mr[j];
                bestder[j] = dp[j];
            }
        }

        //o me muevo a la izquierda 
        bestval = pdp[sz-1]; //mejor val de donde estaba antes
        bestvalpos = mr[sz-1];
        for(int j = sz-1; j>=0; j--){
            bestizq[j] = bestval +bestvalpos - mr[j];
            if(dp[j] < bestizq[j]){
                bestval = dp[j];
                bestvalpos = mr[j];
                bestizq[j] = dp[j];
            }
        }

        rep(j, 0, sz){
            dp[j] = min(dp[j], bestder[j]);
            dp[j] = min(dp[j], bestizq[j]);
            if(mr[j] < a[i].fi) dp[j] += a[i].fi - mr[j];
            if(mr[j] > a[i].se) dp[j] += mr[j] - a[i].se;
            //dp[i][j] += cost(mr[j], a[i].fi, a[i].se);
        }
        pdp = dp;
    }

    ll ans = (1e18);
    rep(j, 0, sz){
        ans = min(dp[j], ans);
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