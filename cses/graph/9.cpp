//https://cses.fi/problemset/task/1672
#include <bits/stdc++.h> //dijkstra para encontrar las menores distancias entre todos los vertices en O(n^3)
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
    int n,m,q; cin >> n >> m >> q;
    vector<vector<pair<lli, lli>>> grafo(n+1, vector<pair<lli, lli>> {});
    vvlli ans(n+1, vlli(n+1, 13e13));
    lli a,b,c;
    forn(i, 0, m){
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b], c);
        ans[b][a] = min(ans[b][a], c);
    }

    forn(i, 1, n+1) ans[i][i] = 0;

    forn(k, 1, n+1){
        forn(i, 1, n+1){
            forn(j, 1, n+1){
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    
    forn(i, 0, q){
        cin >> a >> b;
        if(ans[a][b] > 1e14) cout << -1 << nl;
        else cout << ans[a][b] << nl;
    }

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}