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
    string s; cin >> s;

    int dp[n][n][3];
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, 3) dp[i][j][k] = -10000;
    //vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, -10000)));

    vector<int> a(n);
    rep(i, 0, n){
        if(s[i] == ')') a[i] = -1;
        else a[i] = 1;
    }

    int l=-1, r=-1;
    rep(i, 0, n){
        if(l != -1) break;
        if(a[i] == 1){
            l = i;
            break;
        }
    }
    rep(i, 0, n) if(a[i] == -1) r = i;

    if(l == -1 || r == -1 || l>=r){
        cout << 0 << endl;
        return;
    }

    rep(i, 0, n){
        dp[l][i][1] = 2;
        dp[i][r][1] = 2;
    }
    int ans = 2;
    
    rep(i, l+1, r){
        for(int j = r-1; j>=i+1; --j){
            rep(k, 0, 3){
                dp[i][j][k] = max({dp[i-1][j][k], dp[i][j+1][k], dp[i-1][j+1][k]});
                if((k<2) && (a[i] == -1) && (a[j] == -1)){//puedo meter -1
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j+1][k+1]+2);
                }
                if((k>0) && (a[i] == 1) && (a[j] == 1)){//puedo meter 1
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j+1][k-1]+2);
                }
            }
            ans = max(ans, dp[i][j][1]);
        }
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}