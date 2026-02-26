#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

long double p[8][8][8][8][101];

void solve(){
    int t; cin >> t;
    // probabilidad de llegar de [i][j] a [k][l] en [m] pasos, esto es 8 x 8 x 8 x 8 x 100
    vector<vector<vector<pair<int, int>>>> options(8, vector<vector<pair<int, int>>>(8, vector<pair<int, int>>(0.0)));

    for(int j=0; j<8; j++){
        for(int k=0; k<8; k++){
            if(j>0) options[j][k].push_back({j-1, k});
            if(j<7) options[j][k].push_back({j+1, k});
            if(k>0) options[j][k].push_back({j, k-1});
            if(k<7) options[j][k].push_back({j, k+1});
        }
    }

    rep(i, 0, 8) rep(j, 0, 8) p[i][j][i][j][0] = 1;

    rep(m, 1, t+1) rep(i, 0, 8) rep(j, 0, 8) rep(k, 0, 8) rep(l, 0, 8){
        for(auto [u,v] : options[k][l]) p[i][j][k][l][m] += p[i][j][u][v][m-1]/(long double)options[u][v].size();
    }

    long double ans[8][8]; 
    long double ret = 0.0;
    rep(i, 0, 8) rep(j, 0, 8){
        ans[i][j] = 1;
        rep(k, 0, 8) rep(l, 0, 8){
            ans[i][j] *= (1.0-p[k][l][i][j][t]);
        }
        ret+=ans[i][j];
    } 

    cout << fixed << setprecision(6) << ret << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}