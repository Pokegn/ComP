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
    long long int x; cin >> x;
    long long int y=x;
    vector<int> a(50);
    int k = 0;
    while(x>0){
        a[k] = x%2;
        x/=2;
        k++;
    }
    // cout << "este es" << y << nl;
    // forn(i, 0, k){
    //     cout << a[i] << ' ';
    // }
    // cout << nl;
    int l=0; int r=0;
    while(r<k){
        if(a[r] == 1){
            r ++;
            continue;
        }
        if(a[r] == 0){
            if(l == r || l==r-1){
                r++;
                l = r;
            }
            else{
                a[l] = -1;
                for(int i=l+1; i<r; i++){
                    a[i] = 0;
                }
                a[r] = 1;
                l = r;
                r++;
            }
        }
    }
    //cout << "k" << k << nl;
    if(r>l+1){
        k++;
        a[l] = -1;
        for(int i=l+1; i<r; i++){
            a[i] = 0;
        }
        a[r] = 1;
    }
    cout << k <<nl;
    forn(i, 0, k){
        cout << a[i] << ' ';
    }
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}