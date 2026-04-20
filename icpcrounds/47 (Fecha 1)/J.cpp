#include <bits/stdc++.h>

using namespace std;

#define sz(x) (x).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define endl '\n'
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> dp(1e6+1,0);
vector<ll> dosimpar(1e6+1,0), dospar(1e6+1,0);


void solve(){
    //ll n; cin >> n;
    rep(n, 1, 1000001){
        ll par = n/2; ll impar = n-n/2;
        ll ans = 0;
        ans = (par*(par-1)*(par-2))/6; ans%=MOD;
        ans += (par*(impar)*(impar-1))/2; ans%=MOD;
        if(ans != (dp[n]%1000000007+MOD)%MOD){
            cout << n << ' ' << ans << ' ' << (dp[n]%1000000007+MOD)%MOD <<' ' << dospar[n] << ' ' << dosimpar[n] << endl;
            return;
        }
    }
    return;
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;

    rep(i, 1, 1000001){
        dosimpar[i] = ((i/2)*(i-i/2)) % MOD;
        dospar[i] = ((i*(i-1))/2)%MOD - dosimpar[i]; dospar[i] = dospar[i]%MOD + MOD; dospar[i]%=MOD;
    }

    rep(i, 1, 1000001){
        if(i%2 == 0){
            dp[i] = dospar[i-1] ; 
        }
        else{
            dp[i] = dosimpar[i-1];
        }
        
        dp[i] += dp[i-1]; dp[i] %= MOD;
        // cout << dospar[i] << ' ' << dosimpar[i] << dp[i] << endl;
    }


    while(tt--)
        solve();

    return 0;
}