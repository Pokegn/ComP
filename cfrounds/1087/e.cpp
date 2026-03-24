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

vector<ll> prefix_function(string s) {
    int n = (ll)s.length();
    vector<ll> pi(n);
    for (int i = 1; i < n; i++) {
        ll j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve(){
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    rep(i, 0, q){
        int l,r; cin >> l >> r; l--; r--;
        string st = "";
        rep(j, l, r+1) st+=s[j];
        vector<ll> pi = prefix_function(st);
        vector<ll> b(st.length());
        //cout << "pi: "; rep(j, 0, st.length()) cout << pi[j] << ' '; cout << endl;
        rep(j, 0, st.size()){
            if(pi[j] == 0){
                b[j] = 0; continue;
            } 
            if(pi[pi[j]-1] == 0) b[j] = pi[j];
            else{
                b[j] = b[pi[j]-1];
            }
        }
        //cout << "b: "; rep(j, 0, st.length()) cout << b[j] << ' '; cout << endl;
        vector<ll> dp(st.length()); dp[0] = 1; 
        rep(j, 1, st.length()){
            dp[j] = (b[j] == 0 ? 1 : dp[j-b[j]]+1);
        }
        //cout << "dp: "; rep(j, 0, st.length()) cout << dp[j] << ' '; cout << endl;
        ll ans = 0;
        rep(j, 0, st.length()) ans += dp[j];
        //cout << endl;
        cout << ans << endl;
    }
    //cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}