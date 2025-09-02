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

void solve(){
    string s, t; cin >> s >> t;
    int sl = s.length(); int tl = t.length();
    lli ssc = 0;
    lli tsc = 0;
    forn(i, 0, sl){
        if(s[i]<='9'){
            ssc += s[i]-'0';
            continue;
        }
        if(s[i]<'a'){
            ssc+=20+2*(s[i]-'A');
            continue;
        }
        ssc+=10+1*(s[i]-'a');
    }
    forn(i, 0, tl){
        if(t[i]<='9'){
            tsc += t[i]-'0';
            continue;
        }
        if(t[i]<'a'){
            tsc+=20+2*(t[i]-'A');
            continue;
        }
        tsc+=10+1*(t[i]-'a');
    }
    if(ssc < tsc){
        cout << "Carolina " << tsc << '\n';
    }
    else cout << "Ana " << ssc << '\n';
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}