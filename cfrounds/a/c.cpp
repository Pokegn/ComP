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
    lli a, b, r; cin >> a >> b>>r;
    vi xd(100, 0);
    lli aa, bb;
    aa = a;
    if(b>a){
        a = b;
        b = aa;
    }
    aa=a;
    bb=b;
    int i=0;
    int maxi = 0;
    while(aa>0 || bb>0){
        if(aa%2==1 && bb%2 == 0){xd[i] = 1; maxi = i;}
        aa>>=1;
        bb>>=1;
        i++;
    }
    i-=2;
    //cout << i << " ";

    lli pow = 1;
    forn(j, 0, maxi-1){
        pow*=2;
    }

    vi ans(100,0);
    //cout << pow << " ";
    
    rof(x, maxi-1, 0){
        if(xd[x]==1 && r>=pow){
            r-=pow;
            ans[x]=1;
        }
        pow/=2;
        
    }
    //11010001100111010110111000000110101100011111111111010101111
    //101110011000101001000111111001010011100000000000101010001
    r = 0;
    lli powa = 1;

    forn(j, 0, 63){
        if(ans[j] == 1) r+=powa;
        powa*=2;
    }
    //cout << r << " ";

    cout << (a^r) - (b^r) << nl;

    //cout << (lli) abs((a^r)-(b^r)) << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}