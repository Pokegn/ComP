#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
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

lli ans=0;
lli n;
vector< vector<lli> > tri;

lli caso(lli a,lli b,lli c){
    map<pair<lli, lli>, map<lli, lli>> cosa;
    map<pair<lli, lli>, lli> tamano;
    lli resp = 0;
    forn(i, 0, n-2){
        cosa[{tri[i][a], tri[i][b]}][tri[i][c]]++;
        tamano[{tri[i][a], tri[i][b]}]++;
    }
    forn(i, 0, n-2){
        resp+=cosa[{tri[i][a], tri[i][b]}][tri[i][c]]*(tamano[{tri[i][a], tri[i][b]}] - cosa[{tri[i][a], tri[i][b]}][tri[i][c]]);
        tamano[{tri[i][a], tri[i][b]}]-=cosa[{tri[i][a], tri[i][b]}][tri[i][c]];
        cosa[{tri[i][a], tri[i][b]}][tri[i][c]] = 0;
    }
    return resp;
}

void solve(){
    ans = 0;
    cin >> n;
    tri = vector< vector<lli> > (n-2);
    vlli a(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n-2){
        tri[i] = (vlli {a[i], a[i+1], a[i+2]});
    }

    ans+=caso(0, 1, 2);
    ans+=caso(1,2,0);
    ans+=caso(2,0,1);

    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}