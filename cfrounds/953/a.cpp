#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vlli a(n);
    forn(i,0, n) cin >> a[i];
    int count = 1;
    int top = a[0];
    forn(i, 1, n){
        if(a[i] == top) count++;
        else if(a[i] > top){
            count = 1;
            top = a[i];
        }
    }
    if(top != a[n-1]){
        cout << top+a[n-1] << nl;
        return;
    }
    
    if(count>1){
        cout << 2*top << nl;
        return;
    }

    else{
        int top2 = -1;
        count = 1;
        forn(i, 0, n){
            if(a[i] == top) continue;
            if(a[i] > top2){
                top2 = a[i];
            }
        }
        cout << top + top2 << nl;
        return;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}