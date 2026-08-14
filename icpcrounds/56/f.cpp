#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define reprev(i, a, b) for(int i=b-1; i>=(a); --i)
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
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n){
        rep(j, 0, m){
            mat[i][j] = (int)(s[i][j] - '0');
        }
    }

    int dp[n][m][8];
    //0
    int k = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if(i-1 >= 0){ //si hay siguiente
                    dp[i][j][k] = dp[i-1][j][k] + 1;
                }
            } 
        }
    }
    //1
    k = 1;
    rep(i, 0, n){
        reprev(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if((i-1 >= 0) && (j+1 <= m-1)){ //si hay siguiente
                    dp[i][j][k] = dp[i-1][j+1][k] + 1;
                }
            } 
        }
    }
    //2
    k = 2;
    rep(i, 0, n){
        reprev(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if(j+1 <= m-1){ //si hay siguiente
                    dp[i][j][k] = dp[i][j+1][k] + 1;
                }
            } 
        }
    }
    //3
    k = 3;
    reprev(i, 0, n){
        reprev(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if((i+1 <= n-1) && (j+1 <= m-1)){ //si hay siguiente
                    dp[i][j][k] = dp[i+1][j+1][k] + 1;
                }
            } 
        }
    }
    //4
    k = 4;
    reprev(i, 0, n){
        rep(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if((i+1 <= n-1)){ //si hay siguiente
                    dp[i][j][k] = dp[i+1][j][k] + 1;
                }
            } 
        }
    }
    //5
    k = 5;
    reprev(i, 0, n){
        rep(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if((i+1 <= n-1) && (j-1 >= 0)){ //si hay siguiente
                    dp[i][j][k] = dp[i+1][j-1][k] + 1;
                }
            } 
        }
    }
    //6
    k = 6;
    rep(i, 0, n){
        rep(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if((j-1 >= 0)){ //si hay siguiente
                    dp[i][j][k] = dp[i][j-1][k] + 1;
                }
            } 
        }
    }
    //7
    k = 7;
    rep(i, 0, n){
        rep(j, 0, m){
            if(mat[i][j] == 1) dp[i][j][k] = -1; //si es negro
            else{
                dp[i][j][k] = 0; //default
                if((j-1 >= 0) && (i-1 >= 0)){ //si hay siguiente
                    dp[i][j][k] = dp[i-1][j-1][k] + 1;
                }
            } 
        }
    }

    ll ans = 0;
    vector<pair<int, int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    rep(i, 0, n){
        rep(j, 0, m){
            if(mat[i][j] == 1) continue;
            ll add;
            rep(k, 0, 8){
                ll maxadd = min(dp[i][j][k], dp[i][j][(k+2)%8]);
                add = 0;
                rep(x, 1, maxadd+1){
                    if(dp[i+(dir[k].fi)*x][j+(dir[k].se)*x][(k+3)%8] >= (((k%2) == 0) ? x : 2*x)){
                        add++;
                        //cout << i << ' ' << j << ' ' << k << ' ' << x << endl;
                    }
                }
                ans += add;
                // if((i==4) && (j == 0) && (k == 0)){
                //     cout << dp[i+dir[k].fi][j+dir[k].se][(k+3)%8] << ' ' << (((k%2) == 0) ? 4: 2*4) << endl;
                // }
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