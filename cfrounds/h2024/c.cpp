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
    vi a(n);
    forn(i, 0, n) cin >> a[i];
    lli ans = 0;

    int top1, top2;
    top1 = 0;
    top2 = -1;
    while(top2==-1){
        if(top1 == n){
            cout << 0 << nl;
            return;
        }
        if(a[top1]>=a[top1+1]){
            top1++;
            continue;
        }
        else{
            top2 = top1+1;
            continue;
        }
    }

    int xd = top2;

    forn(i, xd+1, n){
        int niu = a[i];
        if(a[top1] > a[top2]){
            if(niu <= a[top2]){
                top2 = i;
                continue;
            }
            if(niu <= a[top1]){
                top1 = i;
                continue;
            }
            top2 = i;
            ans++;
            //cout << "cocon1 " << i << nl;
            continue;
        }
        else{
            if(niu <= a[top1]){
                top1 = i;
                continue;
            }
            if(niu <= a[top2]){
                top2 = i;
                continue;
            }
            top1 = i;
            ans++;
            //cout << "cocon2 " << i << nl;

            continue;
        }
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}