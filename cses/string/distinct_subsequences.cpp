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
ll MOD = 1000000007;

void solve(){
    string ss; cin >> ss;
    ll n = sz(ss);

    vector<ll> s(n);
    rep(i, 0,n) s[i] = (ll)ss[i]-'a';

    vector<vector<ll>> g(n+1);

    vi last(26, -1);

    for(ll i = n-1; i>=0; i--){
        rep(j, 0, 26){
            if(last[j] != -1){
                g[i+1].push_back(last[j]+1);
            }
        }
        last[s[i]] = i;
    }
    rep(j, 0, 26){
        if(last[j] != -1){
            g[0].push_back(last[j]+1);
        }
    }
    
    vector<ll> cum(n+1, 0);
    cum[0] = 1;

    rep(i, 0, n+1){
        for(auto x: g[i]){
            cum[x] += cum[i];
            cum[x]%=MOD;
        }
    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += cum[i];
        ans%=MOD;
    }

    cout << ans << endl;
    return;        
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}