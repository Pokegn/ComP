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

void solve(){
    lli x,y,k; cin >> x>>y>>k;
    lli mod;
    while(x>=y && k>0){
        mod = x%y;
        if(y-mod>k){
            x+=k;
            k = 0;
            //cout << x << ' ';
        }
        else{
            k-=y-mod;
            x+=y-mod;
            while(x%y == 0){
                x/=y;
                //cout << x << ' ';
            }
        }
    }

    if(x<=y-1 && k>0){
        x = (x+k)%(y-1);
        if(x == 0) x= y-1;
    }
    cout << x << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}