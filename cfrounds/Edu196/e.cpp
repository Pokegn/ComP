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

const ll MOD = 998244353;
vector<ll> ways(5001);
vector<ll> bells(5001);

void bell(ll n){
    vector<ll> p = {1};
    rep(i, 1, n+1){
        vector<ll> curr(i+1, 0);

        curr[0] = p[sz(p)-1];
        rep(j, 1, i+1) curr[j] = (p[j-1] + curr[j-1])%MOD;
        p = curr;
        bells[i] = p[0]%MOD;
    }
    return;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> sizes;

    int alone0 = 0;
    int alone1 = 0;

    ll currsize = 1;
    rep(i, 1, n){
        if(s[i] != s[i-1]) currsize++;
        else{
            if(currsize > 1) sizes.push_back(currsize);
            else{
                if(s[i-1] == '0') alone0++;
                else alone1++;
            }
            currsize = 1;
        }
    }
    if(currsize == 1){
        if(s[n-1] == '0') alone0++;
        else alone1++;
    }
    else{
        sizes.push_back(currsize);
    }

    ll ans = bells[alone0] * bells[alone1];
    ans%=MOD;

    for(auto v: sizes){
        ans *= ways[v];
        ans %=MOD;
    }

    // cout << "sizes: ";
    // for(auto ss : sizes) cout << ss << ' ';
    // cout << endl;
    // cout << alone0 << ' ' << alone1 << endl << endl;
    
    cout << 2*n - alone0 - alone1 << ' ';
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    bell(5000);
    bells[0] = 1;
    // rep(i, 0, 10) cout << bells[i] << ' ';

    ways[0] = 1;
    rep(i, 1, 5001){
        if(i-2 >= 0) ways[i] += ways[i-2];
        if(i-3 >= 0) ways[i] += ways[i-3];
        ways[i] %= MOD;
    }

    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}