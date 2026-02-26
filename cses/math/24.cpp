#include <bits/stdc++.h> //graph coso 2
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

const int sz = 101;

ll modpow(ll b, ll e) {
ll ans = 1;
for (; e; b = b * b % mod, e /= 2)
if (e & 1) ans = ans * b % mod;
return ans;
}

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N) a.d[i][j] = -1;
        rep(i,0,N) rep(j,0,N)
        rep(k,0,N){
            if(d[i][k]>0 && m.d[k][j]>0) if(a.d[i][j] >0 ) a.d[i][j] = min(a.d[i][j], d[i][k]+m.d[k][j]); 
            else a.d[i][j] = d[i][k]+m.d[k][j];
        } 
        return a;
    }

    M operator^(ll p) const {
        bool flag = false;
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
        if (p&1){
            if(flag) a = a*b; 
            else{
                a = b;
                flag = true;
            }
        } 
        b = b*b;
        p >>= 1;
        }
        return a;
    }
};

void solve(){
    int n; cin >> n;
    Matrix<ll, sz> A;
    ll m; cin >> m;
    ll k; cin >> k;

    rep(i, 0, sz) rep(j, 0, sz) A.d[i][j] = -1;

    for(int i=0; i<m; i++){
        ll u,v,w; cin >> u >> v>> w;
        //grafo[u].push_back(v);
        if(A.d[u][v]==-1) A.d[u][v] = w;
        else A.d[u][v] = min(A.d[u][v], w);
    }

    A =  A^k;

    // rep(i, 0, sz){
    //     rep(j, 0, sz){
    //         cout << A.d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << A.d[1][n] << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}