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
#define coso 100001

vlli ans(5*coso, 0);

void llena(){
    ans[0] = 0;
    ans[1] = 1;
    ans[4] = 2;
    lli resp = 2; 
    forn(i, 2, coso){
        if(ans[i] == 0){
            ans[i] = resp;
        }
        else{
            ans[2*i+2] = resp+1;
            resp++;
        }
    }
}

void solve(){
    lli n; cin >> n;
    cout << ans[n] << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    llena();
    while(t--) solve();
    return 0;
}