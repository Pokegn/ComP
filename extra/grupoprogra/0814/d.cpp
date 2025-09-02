#include <vector>
#include <iostream>
#include <queue>
#include <math.h>
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
 
void solve(){
    lli cu, uu, cc, uc;
 
    lli unos, ceros;
    cin >> cc >> cu >> uc >> uu;
    unos = (lli)(sqrt((double)2*uu));
    unos++;
    if(uu == 0) unos = 0;
    ceros = (lli)(sqrt((double)2*cc));
    ceros++;
    if(cc == 0) ceros = 0;
    
    if((unos*(unos-1))/2 != uu){
        std::cout << "Impossible" << nl;
        return;
    }
    if((ceros*(ceros-1))/2 != cc){
        std::cout << "Impossible" << nl;
        return;
    }
    if(cu+uc != ceros*unos){
        std::cout << "Impossible" << nl;
        return;
    }
 
    if(ceros == 0){
        forn(i, 0, unos) std::cout << "1";
        std::cout << nl;
        forn(i, 0, 1e10) cout << "xd";
        return;
    }
    lli xd = uc/ceros;
    forn(i, 0, xd){
        std::cout << "1";
        uc-=ceros;
        unos--;
    }
    forn(i, 0, ceros){
        std::cout << '0';
        if(uc>0 && uc == ceros-i-1){
            std::cout << '1';
            unos--;
            uc = 0;
        }
    }
    forn(i, 0, unos) std::cout << '1';
    std::cout << nl;
 
}
 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}