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
using vi = vector<int>; //xd
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

int n;
vi s;
vi vec;

lli respuesta(int ind){
    vec.assign(n, 0);
    lli ans =0 ;
    vector<char> signo(n-1, '.');

    forn(i, 0, n) vec[i] = s[i];
    vec[ind+1] +=10*vec[ind];
    forn(i, 0, n){
        if(i == ind) continue;
        if(vec[i] != 1) ans+=vec[i];
    }
    return ans;
}

void solve(){
    cin >> n;
    vector<char> d(n); forn(i, 0, n) cin >> d[i];
    lli ans = 1e9;

    s.assign(n, 0);
    forn(i, 0, n){
        s[i] = (int)(d[i]-'0');

        if(s[i] == 0 && n>3){
            cout << 0 << nl;
            return;
        }

    }

    if(n == 2){
        cout << s[0]*10+s[1] << nl;
        return;
    }

    if(n ==3){
        lli a,b,c,d;
        a = s[0]*10+s[1]+s[2];
        b = (s[0]*10+s[1])*s[2];
        c = s[0]+ s[1]*10+s[2];
        d = s[0]*(s[1]*10+s[2]);
        cout << min(min(min(a,b),c),d) << nl;
        return;
    }

    forn(i, 0, n-1){
        ans = min(ans, respuesta(i));
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}