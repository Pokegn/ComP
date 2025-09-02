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
    vlli a(n);
    for(lli &x: a){
        cin >> x;
    }
    sort(a.begin(), a.end());
    if(n == 1){
        cout << 1 << nl;
        return;
    }
    lli g = a[1]-a[0];
    forn(i, 1, n-1){
        g = __gcd(g, a[i+1]-a[0]);
    }
    lli ma = a[n-1];
    lli ans = 0;
    forn(i, 0, n){
        ans+=(ma-a[i])/g;
    }
    int j = n-1;
    while(true){
        if(a[j] == ma -  (n-1 - j)){
            j-=g;
            continue;
        }
        ans+=n-1-j;
        break;
    }
    cout << ma << ' ' << g << nl;
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}