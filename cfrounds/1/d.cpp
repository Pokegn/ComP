#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
#define MOD 998244353

ll xres(ll n, ll r){
    if(n<=3){
        return (n>=r ? 1 : 0);
    }
    ll ans = n/4;
    ans += xres(n-4*(n/4), r);
    return ans;
}

void solve(){
    ll n,x; cin >> n >> x;
    ll ans = 0;
    ans += (xres(x, 2)%MOD)*((xres(n, 1)-xres(x-1, 1))%MOD); ans%=MOD;
    ans += (xres(x, 0)%MOD)*((xres(n, 3)-xres(x-1, 3))%MOD); ans%=MOD;
    // ans += (xres(n, 3) - xres(x-1, 3))%MOD; ans%=MOD;
    cout <<ans << endl;
    return;

    // ll xres2 = x/4 + (x - 4*(x/4) >= 2 ? 1 : 0); xres2%=MOD;
    // ll xres0 = x/4; xres0%=MOD;
    // ll nres2 = n/4 + (n - 4*(n/4) >= 2 ? 1 : 0) + (x%4 == 2); nres2-=xres2; nres2 %=MOD;
    // ll nres0 = n/4 + (x%4 == 0); nres0 -= xres0; nres0 %=MOD;

    // ll ans = (xres2*nres2)%MOD + (nres0*xres0)%MOD; ans%=MOD;
    // cout <<ans << endl;
    
    

    // ll coso = 0;
    // //     bool f1 = false, f2 = false;
    // rep(x, 2, 50){
    //     coso = 0;
    // int coso = 0;
    // rep(k, 1, 10){
    //     coso = 0;
    // for(int i=k; i<k+20; i++){
    //     coso^=i;
        // if(coso == 0 && i-x <= 3) f1 = true;
        // if(coso == 0) f2 = true;
        // if(f2 && !f1){
        //     cout << i << ' '<< x << "!!!" << endl;
        //     return;
        // }
    //     cout << coso << ' ';
    // }
    // cout << endl;
}




int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}