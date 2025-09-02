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
    int n, x; cin >> n >> x;
    int extra=0;
    vi a(n);
    for(int &y: a){
        cin >> y;
    }
    sort(a.begin(), a.end());
    int l, r; l = r = -1;
    int xd=0;


    while(l==-1){


        if(xd == n){
            forn(j,0,n){
                if(x < a[j]){l = j; r = j;
                break;
                }
            }

            if(l==-1){ l = n; r = n;}

            n++; extra=1;
            //cout<< l;
            continue;
        }

        if(a[xd] == x){
            l=xd;
        }

        xd++;

    }

    
    while(r == -1){
        if(xd == n || a[xd]!=x){
            r = xd-1;
            continue;
        }
        xd++;
    }
    //cout << l << ' '<< r << ' ' << (int)(n-1)/2 << nl;
    if(l<=(int)(n-1)/2 && r>=(int)(n-1)/2){
        cout << 0+extra << nl;
        return;
    }
    if(l>(int)(n-1)/2){
        cout << 2*l-n+extra+1 << nl;
        return;
    }
    cout << n-2*r-2+extra << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}