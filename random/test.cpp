#include <bits/stdc++.h>
using namespace std;
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

void sum1(vlli &xd){
    forn(i, 0, xd.size()) xd[i]++;
    return;
}

void solve(){
    vlli equis = {1,2,3};
    forn(i, 0, equis.size()) cout << equis[i] << ' ' ;
    sum1(equis);
    forn(i, 0, equis.size()) cout << equis[i] << ' ' ;


}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t =1;
    while(t--) solve();
    return 0;
}