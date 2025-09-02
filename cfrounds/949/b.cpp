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
    lli n, m; cin >>n>>m;
    if(m==0){
        cout<< n << nl;
        return;
    }
    lli ans = 0;
    lli mod = 1;
    lli n1 = max(n-m, (lli)0);
    lli n2= n;
    lli n3 = n+m;
    forn(i, 0, 50){
        mod*=2;
        if(2*m+1 > mod){
            ans+=mod/2;
            n1/=2; n2/=2; n3/=2;
            continue;
        }
        if(n1%2 == 1 || n2%2==1 || n3%2 == 1){
            ans+=mod/2;
            n1/=2; n2/=2; n3/=2;
            continue;
        }
        n1/=2; n2/=2; n3/=2;
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}