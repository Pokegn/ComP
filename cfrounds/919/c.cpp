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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n; cin >> n;
    vlli d(n);
    lli sz = 0;
    forn(i, 1, n+1){ 
        if(n%i == 0){
            d[sz] = i;
            sz++;
        }
    }

    vlli a(n+1);
    forn(i, 1, n+1) cin >> a[i];

    lli g;
    lli ans = 0;

    lli div;
    forn(i, 0, sz){
        g = -1;
        div = d[i];
        forn(j, 1, div+1){ //j es en que indice el primer arreglo vamos
            forn(k, 0, n/div-1){ //k es en que arreglo estamos comparando
                if(a[j+div*k]==a[j+div*k+div]) continue;
                if(g==-1){
                    g = abs(a[j+div*k]-a[j+div*k+div]);
                    continue;
                }
                g = __gcd(g, abs(a[j+div*k]-a[j+div*k+div]));
                if(g==1) break;
            }
            if(g==1) break;
        }
        if(g != 1) ans++;
    }

    cout << ans << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}