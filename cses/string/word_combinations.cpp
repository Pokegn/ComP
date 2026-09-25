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
#define MOD 1000000007
typedef uint64_t ull;

struct H {
    ull x; H(ull x=0) : x(x) {}
    H operator+ (H o) { return x + o.x + (x+o.x < x); }
    H operator- (H o) { return *this + ~o.x; }
    H operator* (H o) { auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m>>64); }

    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator< (H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11+3;

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string &str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { //hash [a,b)
        return ha[b] - ha[a] * pw[b-a];
    }
};

vector<H> getHashes(string &str, int length){
    if(sz(str) < length) return {};
    H h = 0, pw = 1;
    rep(i, 0, length)
        h = h*C + str[i], pw = pw*C;
    vector<H> ret = {h};
    rep(i, length, sz(str)){
        ret.push_back(h = h*C + str[i] - pw*str[i-length]);
    }
    return ret;
}

H hashstring(string &s){ H h{}; for(char c:s) h = h*C+c; return h;}

void solve(){
    string s; cin >> s;
    int n = sz(s);
    int k; cin >> k;
    vector<string> a(k);
    vector<vector<H>> Hofsize(n+1);
    rep(i, 0, k){
        cin >> a[i];
        Hofsize[sz(a[i])].push_back(hashstring(a[i]));
    } 
    
    // have[hashstring(a[i])] = 1;
    auto hs = HashInterval(s);
    vector<ll> dp(n, 0);
    rep(i, 0, n){
        // if(have[hs.hashInterval(0, i+1)] == 1){
        //     dp[i]++;
        // }
        rep(j, 0, i+1){
            int len = i-j+1;
            for(H hash: Hofsize[len]){
                if(hs.hashInterval(j, i+1) == hash){
                    dp[i] += (j == 0 ? 1:dp[j-1]);
                    dp[i] %=MOD;
                }
            }
        }
    }
    // rep(i, 0, n) cout << dp[i] << ' ';
    // cout << endl;
    cout << dp[n-1] << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}