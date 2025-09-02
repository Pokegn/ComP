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
    lli n, x; cin >> n >> x;
    lli ans = 0;
    forn(a, 1, n){
        for(lli b = 1; a*b+a+b <= n; b++){
            if(a*b+a+b>n || a+b+1>x) continue;
            lli l,r;
            l = 1;
            r = n;
            while(l!=r){
                lli mid = (l+r+1)/2;
                if(a*b+a*mid+b*mid <=n && a+b+mid <=x) l = mid;
                else r = mid-1;
            }
            ans+=r;
        }
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}