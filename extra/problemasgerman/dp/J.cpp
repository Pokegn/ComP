#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
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

vector<long double> mapa(27000001);
int n;
lli asd = 0;

lli vetoi(lli a, lli b, lli c, lli d){
    return d+300*c+300*300*b;
}

void ans(lli a, lli b, lli c, lli d){
    asd++;
    if(a == n){
        return;
    }

    if(mapa[vetoi(a,b,c,d)] != 0) return;

    long double p = (long double)1 - (long double)(a/(long double)n);
    //cout << p << nl;
    double ret = 0;
    if(d>0){
        if(mapa[vetoi(a,b,c+1,d-1)] == 0) ans(a,b,c+1,d-1);
        ret += (mapa[vetoi(a,b,c+1,d-1)])*d;
    }
    if(c>0){
        if(mapa[vetoi(a,b+1,c-1,d)] == 0) ans(a,b+1,c-1,d);
        ret += (mapa[vetoi(a,b+1,c-1,d)])*c;
    }
    if(b>0){
        if(mapa[vetoi(a+1,b-1,c,d)] == 0) ans(a+1,b-1,c,d);
        ret += (mapa[vetoi(a+1,b-1,c,d)])*b;
    }

    mapa[vetoi(a,b,c,d)] = ret/(n-a)+((long double)1/p);
    return;
}

void solve(){
    vlli ini(4);
    forn(i, 0, 4) ini[i] = 0;
    cin >> n;
    mapa[vetoi(n,0,0,0)] = 0;
    int x;
    forn(i, 0, n){
        cin >> x;
        ini[x]++;
    }

    ans(ini[0], ini[1], ini[2], ini[3]);
    cout << setprecision(13) << mapa[vetoi(ini[0], ini[1], ini[2], ini[3])] << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}