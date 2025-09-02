#include <bits/stdc++.h>
using namespace std;
template <typename T, int D>
struct Vector : public vector<Vector<T, D - 1>> {
    static_assert(D > 0);
    template<typename... Args>
    Vector(int sz = 0, Args... args) : vector<Vector<T, D - 1>>(sz, Vector<T, D - 1>(args...)) {}
};
template <typename T>
struct Vector<T, 1> : public vector<T> {
    Vector(int sz = 0, const T& val = T()) : vector<T>(sz, val) {}
};

template <typename T>
struct Matrix : public vector<vector<T>> {
    Matrix(int hei = 0, int wid = 0, const T& val = T()) : vector<vector<T>>(hei, vector<T>(wid, val)) {}
};
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void llena(vlli &a, lli i, int p){
    if(a[2*i]==-1) llena(a, 2*i, p-1);
    if(a[2*i+1]==-1) llena(a, 2*i+1, p-1);
    if(p%2==1) a[i] = a[2*i]|a[2*i+1];
    if(p%2==0) a[i] = a[2*i]^a[2*i+1];
}

void actualiza(vlli &a, lli i, int p){
    i/=2;
    p++;
    while(i>=1){
        if(p%2==1) a[i] = a[2*i]|a[2*i+1];
        if(p%2==0) a[i] = a[2*i]^a[2*i+1];
        i/=2;
        p++;
    }
}

void solve(){
    lli n, m; cin >> n >> m;
    lli pisos = n;
    n = 1<<(n+1);
    //cout << n;
    vlli a(n+1, -1);
    lli x = 0;
    forn(i, n/2, n){
        cin >> a[i];
    }

    llena(a, 1, pisos);
    //forn(i, 1, n) cout << a[i] << ' ';

    lli p, b;
    forn(i, 0, m){
        cin >> p >> b;
        a[n/2+p-1] = b;
        actualiza(a, n/2+p-1, 0);
        cout << a[1] << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}