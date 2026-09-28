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

typedef uint64_t ull;
// const ll MOD = 1<<64 - 1;

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

const int MAXN = 4*200000;
H st[MAXN];
vector<H> a(MAXN,0);

void build(ll u, ll l, ll r){
    if(l==r){
        st[u]=a[l];
        return;
    }
        ll mid =  (l+r)/2;
        build(2*u+1, l, mid);
        build(2*u+2, mid+1, r);
        st[u] = st[2*u+1]+st[2*u+2];
}

void update(ll u, ll l, ll r, ll i, H x){
    if(l == r){
        a[i]=x;
        st[u]=x;
        return;
    }
    ll mid = (l+r)/2;
    if(i <= mid){
        st[u]= st[u]+x-a[i];
        update(2*u+1, l, mid, i, x);
    }
    else{
        st[u]= st[u]+x-a[i];
        update(2*u+2, mid+1, r, i, x);
    }
}

H query(ll u, ll l, ll r, ll s, ll e){
    if (s>r || e<l){
        return 0;
    }
    if(s<=l && r<=e){
        return st[u];
    }
    ll mid = (l+r)/2;
    return query(2*u+1, l, mid, s, e) 
    + query(2*u+2, mid+1, r, s, e);
}

ll fexp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
} //llamas fexp(x, m-2, m)

void solve(){
    int n,m; cin >> n >> m;
    string s; cin >> s;
    string sorig = s;

    // return;
    vector<vector<int>> queries(m, vector<int>(3));
    char ccc;
    rep(i, 0, m) rep(j, 0, 3){
        if(j ==2){
            cin >> ccc;
            queries[i][j] = (ll)(ccc);
        }
        else cin >> queries[i][j];
    }

    vector<H> potencias(sz(s));
    H poto = H(1);
    potencias[0] = poto;
    rep(i, 1, n){
        potencias[i] = potencias[i-1]*C;
    }
    vector<H> a(sz(s));
    rep(i, 0, n){
        a[i] = H(s[i])*potencias[i];
    }

    cout << endl;
    rep(i, 0, n){
        cout << a[i].x << endl;
    } 
    cout << endl;

    // a = getHashes(s, sz(s));
    build(0, 0, n-1);

    rep(i, 0, m){
        ll tipo, k, aa, b, x;
        tipo = queries[i][0];
        if(tipo == 1){
            k = queries[i][1], x = queries[i][2];
            update(0, 0, n-1, k-1, H(s[k-1])*potencias[k-1]);
        }
        if(tipo == 2){
            aa = queries[i][1], b = queries[i][2];
            //cout << query(0, 0, n-1, aa-1, b-1).x << endl;
        }
    }

    cout << endl;
    rep(i, 0, n){
        cout << a[i].x << endl;
    } 
    cout << endl;

    // rep(i, 0, n){
    //     cout << (char)(a[i].x);
    // } cout << endl;

    s = sorig;
    reverse(s.begin(), s.end());
    
    rep(i, 0, n){
        a[i] = H(s[i])*potencias[i];
    }

    build(0, 0, n-1);

    cout << endl;
    rep(i, 0, n){
        cout << a[i].x << endl;
    } 
    cout << endl;

    rep(i, 0, m){
        ll tipo, k, x, aa, b;
        tipo = queries[i][0];
        if(tipo == 1){
            k = queries[i][1], x = queries[i][2];
            k--;
            update(0, 0, n-1, n-1-k, H(s[n-k-1])*potencias[n-k-1]);
        }
        if(tipo == 2){
            aa = queries[i][1], b = queries[i][2];
            aa--; b--;
            //cout << query(0, 0, n-1, n-1-b, n-1-aa).x << endl;
        }
    }

    cout << endl;
    rep(i, 0, n){
        cout << a[i].x << endl;
    } 
    cout << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}