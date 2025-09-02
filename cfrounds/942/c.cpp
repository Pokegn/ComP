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
    lli n, k; cin >> n >> k;
    vlli a(n);
    forn(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    vlli b(n);
    forn(i, 0, n-1){
        b[i] = a[i+1]-a[i];
    }

    int i = 0;
    lli mon;
    lli ans = a[0]*n; //????????
    lli r = 0;
    forn(i, 0, n) if(a[i] > a[0]) ans++;
    while(k>0){
        r = 0;
        if(i == n-1){
            ans = n*a[0] + k;
            k = 0;
            cout << max(ans-n+1, (lli)0) << nl;
            return;
        }
        if(b[i] == 0){
            i++;
            continue;
        }
        mon = min(b[i]*(i+1), k);

        if(b[i]*(i+1)>k){
            r = k - (k/(i+1))*(i+1);
        }
        k-=mon;
        a[0] += mon/(i+1);
        i++;

    }
    ans = n*a[0];
    forn(i, 0, n) if(a[i] > a[0]) ans++;
    ans+=r;
    cout << max(ans-n+1, (lli)0)<< nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}