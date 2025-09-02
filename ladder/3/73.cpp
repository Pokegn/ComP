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
lli MOD = 1e8;

vvlli com;
void combina(lli n){
    com.assign(n+1, vlli(n+1));
    forn(i, 0, n+1){
        com[0][i] = 0;
        com[i][0] = 1;
        com[i][i] = 1;
    }
    forn(i, 1, n+1){
        forn(j, 1, n+1){
            if(i>j) com[i][j] = (com[i-1][j] + com[i-1][j-1])%MOD;
            if(i<j) com[i][j] = 0;
        }
    }
}

void solve(){
    
    lli n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    vvlli dp1(120, vlli(120, 0)); //guarda cuantas no beautiful 
    vvlli dp2(120, vlli (120, 0));
    dp1[0][0] = 1; dp2[0][0] = 1; //n1=0 y n2=0 nos da 0 feos
    forn(i, 1, n2+1){
        dp1[0][i] = 0;
        dp1[i][0] = 0;
    }
    forn(i, 1, n1+1){
        dp2[i][0] = 0;
        dp2[0][i] = 0;
    }
    forn(i, 0, k1+1){
        dp1[i][0] = 1;
    }
    forn(i, 0, k2+1){
        dp2[0][i] = 1;
    }
    forn(x, 1, n1+1){
        forn(y, 1, n2+1){
            if(x-1>=0) dp1[x][y] += dp1[x-1][y];
            if(x-k1-1>=0) dp1[x][y] -= dp2[x-k1-1][y];
            if(x-1>=0) dp1[x][y] += dp2[x-1][y];
            dp1[x][y] = (dp1[x][y]+MOD)%MOD;


            if(y-1>=0) dp2[x][y] += dp2[x][y-1];
            if(y-k2-1>=0) dp2[x][y] -= dp1[x][y-k2-1];
            if(y-1>=0) dp2[x][y] += dp1[x][y-1];
            dp2[x][y] = (dp2[x][y]+MOD)%MOD;
        }
    }

    cout << (dp1[n1][n2] + dp2[n1][n2])%MOD << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}