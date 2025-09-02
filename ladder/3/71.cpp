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
    string s; cin >> s;
    lli sz = s.length();
    vi rep(200000,1);
    vector<char> c(200000);
    c[0] = s[0];
    int i=1;
    int j=0;
    while(i<sz){
        if(s[i] == s[i-1]){
            rep[j]++;
        }
        else{
            j++;
            c[j] = s[i];
        }
        i++;
    }
    j++;
    //lli ans = 0;
    //forn(x, 0, j) cout << rep[x] << ' '; cout << nl;
    forn(x, 0, j){
        if(rep[x]>2){
            //ans+=rep[x]
            -2;
            rep[x] = 2;
        }
    }

    forn(x, 1, j){
        if(rep[x] == 2 && rep[x-1] == 2){
            //ans++;
            rep[x]--;
        }
    }

    forn(x, 0, j){
        forn(y, 0, rep[x]){
            cout << c[x];
        }
    }
    cout << nl;
    //cout << ans << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}