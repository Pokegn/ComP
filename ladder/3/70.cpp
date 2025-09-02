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
    lli n, avg, r; cin>> n >> r >> avg;
    vector<pair<lli, lli>> a(n);
    lli faltan = n*avg;
    lli ans = 0;
    forn(i,0,n){
        cin >> a[i].second >> a[i].first; //grade es el segundo, essays es primero
        faltan -=a[i].second;
    }
    sort(a.begin(), a.end());
    int i = 0;
    while(faltan > 0){
        if(r-a[i].second < faltan){
            ans += (r-a[i].second)*a[i].first;
            faltan-= r-a[i].second;
            i++;
            continue;
        }
        else{
            ans += faltan*a[i].first;
            faltan = 0;
            continue;
        }
    }
    cout << ans << nl;


}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}