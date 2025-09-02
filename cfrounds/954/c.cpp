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
    lli m,n; cin >> n >> m;
    vector<int> s;
    char d;
    forn(i,0,n){
        cin >> d;
        s.push_back((int)(d-'a'));
    }
    vlli ind(m);
    forn(i, 0, m) cin >> ind[i];
    forn(i, 0, m) ind[i]--;

    vector<int> c(m);
    char temp;
    forn(i, 0, m){
        cin >> temp;
        c[i] = (int)(temp - 'a');
    }

    sort(c.begin(), c.end());
    sort(ind.begin(), ind.end());

    lli j = 0;
    forn(i, 0, m){
        if(i>0 && ind[i] == ind[i-1]) continue;
        s[ind[i]] = c[j];
        j++;
    }

    forn(i, 0, n) cout << (char)('a'+s[i]);
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}