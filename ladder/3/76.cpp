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
    int n, p; cin >> n >> p;
    vector<char> s(n+1);
    forn(i, 1, n+1) cin >> s[i];
    int mid = (n+1)/2;
    if(p>mid){
        if(n%2==1) p = 2*mid-p;
        else p = 1 + 2*mid-p;
    } 
    lli ans = 0;
    int maxi=-1, mini=n+1;
    lli xd;
    forn(i, 1, mid+1){
        xd = abs((int)(s[i]-s[n+1-i])); 
        ans += min(xd, 26-xd);
        if(xd != 0){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
    }
    if(maxi == -1){
        cout << "0" << nl;
        return;
    }

    if(abs(p-mini)<abs(maxi-p)){
        ans+=abs(p-mini);
        ans+=maxi-mini;
    }
    else{
        ans+=abs(p-maxi);
        ans+=maxi-mini;
    }
    cout << ans << nl;
    return;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}