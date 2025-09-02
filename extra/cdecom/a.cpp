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
    string s;
    int personasadentro = 0;
    int personasafuera = 0;
    int ans = 0;
    while(cin >> s){
        int len = s.length();
        personasadentro = 0;
        personasafuera = 0;
        ans = 0;

        forn(i, 0, len){
            if(s[i] == '+'){
                if(personasafuera == 0){
                    ans++;
                }
                else personasafuera--;
                personasadentro++;
            }
            else{
                if(personasadentro == 0){
                    ans++;
                }
                else personasadentro--;
                personasafuera++;
            }
        }
        cout << ans << nl;
    }
}

 
int main(){
    int t=1;
    while(t--) solve();
    return 0;
}