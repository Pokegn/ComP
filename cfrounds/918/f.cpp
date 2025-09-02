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

vlli a;
lli inversions(int l, int r){
    if(l==r) return 0;
    lli anss = inversions(l,l+(r-l)/2) + inversions(l+(r-l)/2+1,r);
    sort(a.begin()+l, a.begin()+l+(r-l)/2+1);
    sort(a.begin()+l+(r-l)/2+1, a.begin()+r+1);
    int x = l, y = l+(r-l)/2+1;
    int curr=0;
    lli ans=0;
    int yasumado = 0;
    while(x<=l+(r-l)/2){
        if(y == r && yasumado == 0){
            if(a[x]>a[y]){
                yasumado = 1;
                curr++;
            }
        }
        if(a[x]<a[y] || y==r){
            ans+=curr;
            if(x<=l+(r-l)/2){
                x++;
                continue;
            }
            else break;
        }
            curr++;
            y++;
            continue;
    }
    return anss + ans;
}


void solve(){
    int n; cin >>n;
    vector<pair<lli, lli>> p(n);
    int gr=0;
    int gl=0;
    forn(i, 0, n){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    
    a.assign(n, 0);
    forn(i,0,n){ a[i] = p[i].second;}

    cout << inversions(0, n-1) << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}