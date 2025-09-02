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


void solve(){
    lli n; cin >> n;
    vlli a(n);
    vlli b(n+1);
    forn(i, 0, n){
        cin >> a[i];
    }
    forn(i, 0, n+1){
        cin >> b[i];
    }
    lli mindis = 1e10;
    
    lli x, y;
    forn(i, 0, n){
        x = a[i]; y = b[i];
        if(x>y) swap(x, y);

        if(x>b[n]){ mindis = min(mindis, x-b[n]+1);
        continue; }

        if(x<=b[n] && y>=b[n]){ mindis = 1;
        continue;}

        mindis = min(mindis, b[n]-y+1);
    }

    lli ans=0;
    forn(i, 0, n) ans+=(b[i] > a[i] ? b[i]-a[i] : a[i]-b[i]);
    ans+=mindis;
    std::cout << ans << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}