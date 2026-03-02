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

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
//god
ll modpow(ll b, ll e){
    ll ans = 1;
    for(; e; b = b*b % mod, e/=2)
        if(e&1) ans = ans*b%mod;
    return ans;
}

typedef vector<ll> vl;
void ntt(vl &a){
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2,1);
    for(static int k = 2, s = 2; k<n; k*=2, s++){
        rt.resize(n);
        ll z[] = {1, modpow(root, mod>>s)};
        rep(i, k, 2*k) rt[i] = rt[i/2] * z[i&1] % mod;
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i/2] | (i&1) << L) / 2;
    rep(i, 0, n) if(i< rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k<n; k*=2)
        for(int i=0; i<n; i+=2*k) rep(j, 0, k){
            ll z = rt[j+k]*a[i+j+k] % mod, &ai = a[i+j];
            a[i+j+k] = ai-z+(z>ai ? mod:0);
            ai += (ai+z>=mod ? z - mod : z); 
        }
}

vl conv(const vl &a, const vl &b){
    if(a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod-2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i, 0, n)
        out[-i & (n-1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin()+s};
}

void solve(){
    int n; cin >> n;
    int sz = 1<<15;
    vector<ll> a(sz, 0), b(sz, 0);
    rep(i,0 ,n+1) cin >> a[i];
    //reverse(a.begin(), a.end());
    rep(i, 0,n+1) cin >> b[i];
    //reverse(b.begin(), b.end());

    vector<ll> nt = conv(a, b);
    rep(i, 0, 2*n+1) cout << nt[i] << ' ';
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}