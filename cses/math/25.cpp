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

struct Fraction{
    ll n,d;
    Fraction(ll num, ll den = 1){
        n = num; d = den;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction((n * other.d + other.n * d)%mod,
                        (d * other.d)%mod);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction((n * other.d - other.n * d)%mod,
                        (d * other.d)%mod);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction((n * other.n)%mod,
                        (d * other.d)%mod);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction((n * other.d)%mod,
                        (d * other.n)%mod);
    }
};

ll modpow(ll b, ll e) {
ll ans = 1;
for (; e; b = b * b % mod, e /= 2)
if (e & 1) ans = ans * b % mod;
return ans;
}

typedef vector<ll> vd;
int solveLinear(vector<vd>& A, vd& b, vd& x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);
    rep(i,0,n) {
        ll v = 0, bv = 0;
        rep(r,i,n) rep(c,i,m)
        if ((v = abs(A[r][c])) > bv)
        br = r, bc = c, bv = v;

        if (bv <= 0) {
            rep(j,i,n) if (abs(b[j]) > 0) return -1;
            break;
        }

        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) swap(A[j][i], A[j][bc]);

        bv = modpow(A[i][i], mod-2);

        rep(j,i+1,n) {
            ll fac = A[j][i] * bv % mod;
            b[j] -= fac * b[i] % mod;
            b[j] %= mod;
            rep(k,i+1,m){
                A[j][k] -= fac*A[i][k];
                A[j][k] %= mod;
            } 
        }
        rank++;
    }
    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i]*=  modpow(A[i][i], mod-2);
        b[i]%=mod;
        x[col[i]] = (b[i]+mod)%mod;
        rep(j,0,i){
            b[j] -= A[j][i] * b[i];
            b[j] %=mod;
        } 
    }
    return rank; // (multiple so lutions i f rank < m)
}

void solve(){
    ll n,m; cin >> n >> m;
    vector<vd> A(n, vd(m));
    vd b(n);
    vd x(m);
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> A[i][j];
        }
        cin >> b[i];
    }
    if(solveLinear(A, b, x) == -1){
        cout << -1 << endl;
        return;
    }
    for(auto xd: x){
        cout << xd << ' ';
    }
    cout << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}