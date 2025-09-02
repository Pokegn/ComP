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

void solve(){
    int n,k; cin >> n >> k;
    vi a(n);
    for(int &x: a) cin >> x;
    lli sum=0;
    lli mini;
    lli ans=0;
    forn(i, 0, n){
        sum+=a[i];
        if(i==k-1) mini=sum;
        if(i>=k){
            sum-=a[i-k];
            mini = min(sum, mini);
            if(mini==sum) ans=i-k+1;
        }
    }
    cout << ans+1 << '\n';
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}