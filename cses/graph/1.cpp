//Counting Rooms https://cses.fi/problemset/task/1192
#include <bits/stdc++.h> //dfs para numero de componentes conexas
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

vector<vector<char>> tabla;

void dfs(int x, int y){
    tabla[x][y] = '#';
    for(int i=x-1; i<=x+1; i+=2){
        if(i<0 || i>tabla.size()-1) continue;
        if(tabla[i][y] == '.') dfs(i, y);
    }
    for(int j=y-1; j<=y+1; j+=2){
        if(j<0 || j>tabla[0].size()-1) continue;
        if(tabla[x][j] == '.') dfs(x, j);
    }
}

void solve(){
    int ans = 0;
    int n, m; cin >> n >> m;
    tabla.assign(n, vector<char> (m));
    forn(i, 0, n){
        forn(j, 0, m){
            cin >> tabla[i][j];
        }
    }
    forn(i, 0, n){
        forn(j, 0, m){
            if(tabla[i][j]=='.'){
                ans++;
                //cout << i << ' ' << j << nl;
                dfs(i, j);
            }
        }
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}