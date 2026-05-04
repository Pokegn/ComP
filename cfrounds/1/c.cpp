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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    vector<ll> dp(n+1);
    dp[0] = 0;
    dp[1] = 1 - (s1[0] == s2[0]);
    rep(i, 2, n+1){
        if(s1[i-1] == s2[i-1]){
            dp[i] = dp[i-1];
        }
        else dp[i] = dp[i-1]+1;

        ll otro = dp[i-2];
        otro+= 2 -(s1[i-1] == s1[i-2]) - (s2[i-1] == s2[i-2]);
        dp[i] = min(dp[i], otro);
    }

    cout << dp[n] << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}