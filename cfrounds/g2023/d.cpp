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
    int n; cin >> n;
    if(n==1){
        cout << 1 << nl;
        return;
    }
    cout << 196;
    forn(i,0,n-3) cout << 0;
    cout << nl;

    forn(i,0,(n-1)/2){
        cout << 1;
        forn(j,0,i) cout << 0;
        cout << 6;
        forn(j,0,i) cout << 0;
        cout << 9;
        forn(j,0,n-2*i-3) cout << 0;
        cout <<nl;

        cout << 9;
        forn(j,0,i) cout << 0;
        cout << 6;
        forn(j,0,i) cout << 0;
        cout << 1;
        forn(j,0,n-2*i-3) cout << 0;
        cout <<nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}