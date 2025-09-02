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

vector<long long int> a;
int caso(long long int k){ //xd es mayores - menores
    int l =0; int r = 0;
    int xd = 0;
    if(a[0] >= k) xd++;
    else xd--;
    int n = a.size();
    while(r < n){

        if(l!=r && xd>0) return 1;

        r++;

        if(r == n) break;

        if(xd < 0 && a[r] >= k){
            l = r;
            xd = 1;
            continue;
        }

        if(a[r]>=k) xd++;
        else xd--;
    }
    return 0;
}

void solve(){
    lli n; cin >> n;
    a.assign(n, 0);
    forn(i, 0, n) cin >> a[i];
    vlli b(n);
    forn(i, 0, n) b[i] = a[i];
    sort(b.begin(), b.end());

    int l = 0;
    int r = n-1;
    int m;
    int maxi = 0;
    while(r-l>1){
        m = (l+r)/2;
        if(caso(b[m]) == 1){
            l = m;
            maxi = max(m, maxi);
        }
        else{
            r = m;
        }
    }

    if(caso(b[l]) == 1) maxi = max(l, maxi);
    if(caso(b[r]) == 1) maxi = max(r, maxi);

    cout << b[maxi] << nl; 

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}