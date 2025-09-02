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
    // int a, b, c; cin >> a >> b >> c;
    // cout << (a^b) + (b^c) + (c^a) << nl;
    lli l, r; cin >> l >> r;
    lli pot = 1<<30;
    lli xd = 0;
    lli maxi = 0;
    lli li = l, ri= r;
    while(l>0 || r>0){
        xd++;
        if(l%2 != r%2) maxi = xd;
        l/=2; r/=2;
    }

    lli maxpot = (1<<(maxi-1));
    lli a,b,c;
    a = ((lli)(ri/maxpot))*maxpot;
    c = a-1;
    if(c != li) b = li;
    else b = ri;
    lli ans = (1<<maxi) - 1;
    ans*=2;
    //cout << ans << nl;
    cout << a << ' ' << b << ' ' << c << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}