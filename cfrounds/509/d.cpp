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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n,h; cin >> n >> h;
    vlli x1(n);
    vlli x2(n);
    forn(i, 0, n){
        cin >> x1[i] >> x2[i];
    }

    vlli free(n);
    vlli costo(n+1, -1); //para llegar del i-1 al i
    forn(i, 0, n){
        free[i] = x2[i]-x1[i];
        if(i>0){
            costo[i] = x1[i] - x2[i-1];
        }
    }
    costo[n] = 1e10;

    lli l = 1; 
    lli r = 1;
    lli currcost = 0;
    lli currtotal = free[0];
    lli totalmax = free[0];
    while(l<n){ //i es la cantidad de mamadas que tienen completas
        while(currcost + costo[r] <= h){
            r++;
            currcost+=costo[r];
            currtotal+=free[r-1];
        } 
        r--;
        currcost-=costo[r];

        if(currcost + costo[r] > h){
            totalmax = currtotal + h;
        }
        r++;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}