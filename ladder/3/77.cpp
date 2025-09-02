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
    lli n, k; cin >> n >> k;
    vlli a(n+1);
    vi xd(10000000, 0);
    lli l,r; l=r=-1;
    forn(i, 1, n+1) cin >> a[i];
    if(k==1){
        cout << 1 << ' '<< 1 << nl;
        return;
    }
    lli sz = 0;

    lli i=1;
    while(sz<k && i<n+1){
        if(xd[a[i]]==0) sz++;
        xd[a[i]]++;
        i++;
    }

    i--;
    r = i;

    if(sz<k){
        cout << "-1 -1" << nl;
        return;
    }
    else{
        i=1;
        while(1 == 1){
            if(xd[a[i]]>1){
                xd[a[i]]--;
                i++;
                continue;
            }

            cout << i << ' ' << r << nl;
            break;
        }
        return;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}
    // l = 1;
    // forn(i, 2,n+1){
    //     cin >> a[i];
    //     if(a[i]==a[i-1] && l == i-1) l++;
    // }

    // lli i = l+1;
    // set<lli> xd;
    // xd.insert(a[l]);