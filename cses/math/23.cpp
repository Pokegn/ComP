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
#define pb push_back
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
#define mod 1000000007

ll modpow(ll b, ll e) {
ll ans = 1;
for (; e; b = b * b % mod, e /= 2)
if (e & 1) ans = ans * b % mod;
return ans;
}

vector<ll> berlekampMassey(vector<ll> s) {
int n = sz(s), L = 0, m = 0;
vector<ll> C(n), B(n), T;
C[0] = B[0] = 1;
ll b = 1;
rep(i,0,n) { ++m;
ll d = s[i] % mod;
rep(j,1,L+1) d = (d + C[j] * s[i - j]) % mod;
if (!d) continue;
T = C; ll coef = d * modpow(b, mod-2) % mod;
rep(j,m,n) C[j] = (C[j] - coef * B[j - m]) % mod;
if (2 * L > i) continue;
L = i + 1 - L; B = T; b = d; m = 0;
}
C.resize(L + 1); C.erase(C.begin());
for (ll& x : C) x = (mod - x) % mod;
return C;
}

typedef vector<ll> Poly;
    ll linearRec(Poly S, Poly tr, ll k) {
    int n = sz(tr);
    auto combine = [&](Poly a, Poly b) {
    Poly res(n * 2 + 1);
    rep(i,0,n+1) rep(j,0,n+1)
    res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
    for (int i = 2 * n; i > n; --i) rep(j,0,n)
    res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
    res.resize(n + 1);
    return res;
    };
    Poly pol(n + 1), e(pol);
    pol[0] = e[1] = 1;
    for (++k; k; k /= 2) {
    if (k % 2) pol = combine(pol, e);
    e = combine(e, e);
    }
    ll res = 0;
    rep(i,0,n) res = (res + pol[i + 1] * S[i]) % mod;
    return res;
}

void solve(){
    ll n; cin >> n;
    //vector<vector<ll>> grafo(n+1, vector<ll>(0));
    vector<pair<ll, ll>> edge;

    ll m; cin >> m;
    ll k; cin >> k;
    for(int i=0; i<m; i++){
        ll u,v; cin >> u >> v;
        //grafo[u].push_back(v);
        edge.push_back({u, v});
    }

    vector<ll> ans(0);
    vector<ll> paths(n+1, 0);
    paths[1] = 1;
    ans.push_back(paths[n]%mod);
    for(int j=1; j<2*n; j++){
        vector<ll> newpaths(n+1, -1);
        for(auto e: edge){
            newpaths[e.second] += paths[e.first];
            newpaths[e.second]%=mod;
        }
        paths = newpaths;
        ans.push_back(paths[n]%mod);
    }

    vector<ll> vec = berlekampMassey(ans);
    // for(auto v: vec) cout << v << ' ';
    // cout << endl;
    // return;
    for(auto v: vec) v = (v%mod+mod)%mod;
    ll answer = linearRec(ans, vec, k);
    cout <<answer%mod << endl;





}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}