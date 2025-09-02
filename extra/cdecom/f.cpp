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
    map<string, string> fila;
    map<string, string> fila2;

    lli n; cin >> n;
    string s,t;
    forn(i, 0, n-1){
        cin >> s >> t;
        fila.insert({s,t});
        fila2.insert({t,s});

    }

    string forst = "NO HAY";
    for(auto i = fila.begin(); i!= fila.end(); i++){
        auto encontrado = fila.find(i->second);
        if(encontrado == fila.end()){
            forst = i->second;
        }
    }

    s = forst;
    while(true){
        cout << s << '\n';
        auto encontrado = fila2.find(fila2[s]);
        if(encontrado == fila2.end()){
            cout << fila2[s];
            return;
        }
        else s = fila2[s];
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}