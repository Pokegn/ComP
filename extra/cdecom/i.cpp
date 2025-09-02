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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vlli segtree(3000000);
vlli a;
void segbuild(lli v, lli l, lli r){
    if(l == r) segtree[v] = a[l];
    else{
        int mid = (l+r)/2;
        segbuild(2*v, l, mid);
        segbuild(2*v+1, mid+1, r);
        segtree[v] = segtree[2*v]*segtree[2*v+1];
    }
}

void update(lli v, lli x, lli i, lli l, lli r){
    if(l == r){
        segtree[v] = x;
        a[i] = segtree[v];
        return;
    }
    int mid = (l+r)/2;
    if(i<=mid){
        update(2*v, x, i, l, mid);
        segtree[v] = segtree[2*v]*segtree[2*v+1];
        return;
    }
    update(2*v+1, x, i, mid+1, r);
    segtree[v] = segtree[2*v]*segtree[2*v+1];
    return;
}

int prod(lli v, lli l, lli r, lli s, lli e){
    if(s>r || e<l) return 1;
    if(s<=l && r<=e){
        return segtree[v];
    }
    int mid = (l+r)/2;
    return prod(2*v, l, mid, s, e)*prod(2*v+1, mid+1, r, s, e);
}

void solve(){
    lli n; cin>> n;
    lli q; cin >> q;
    a.assign({2*n+1000, 0});
    lli x;
    forn(i, 1, n+1){
        cin >> x;
        if(x > 0) x=1;
        if(x<0) x = -1;
        a[i] = x;
    }

    segbuild(1, 1, n);

    string c;
    forn(i, 0, q){
        cin >> c;
        if(c == "C"){
            lli I, V; cin >> I >> V;
            if(V>0) V =1;
            if(V<0) V = -1;
            update(1, V, I ,1,n);
            a[I] = V;
        }
        else if(c == "M"){
            lli A, B; cin >>A >>B;
            lli k = prod(1, 1, n, A, B);
            if(k > 0) cout << '+' << '\n';
            else if(k < 0) cout << '-' << '\n';
            else cout << '0' << '\n';
        }
    }


}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}