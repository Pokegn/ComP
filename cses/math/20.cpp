#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
#define MOD 1000000007

ll fexp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


void solve(){
    ll n; cin >> n;
    if(n==1){
        cout << 2 << endl;
        return;
    }
    ll ans = 0;
    ll eje1, eje2, eje4;
    if(n%2 == 0){
        eje1 = fexp(2, n*n, MOD);
        eje2 = fexp(2, n*n/2, MOD);
        eje4 = fexp(2, (n/2)*(n/2), MOD);
    }
    else{
        eje1 = fexp(2, n*n, MOD);
        eje2 = fexp(2, (n*n)/2+1, MOD);
        eje4 = fexp(2, (n*n)/4+1, MOD);
    }
    ll s1, s2, s3;
    s1 = eje1 - eje2; s1%=MOD; s1 *= fexp(4, MOD-2, MOD); s1%=MOD;
    s2 = eje2 - eje4; s2%=MOD; s2 *= fexp(2, MOD-2, MOD); s2%=MOD;
    s3 = eje4;

    ans = s1+s2+s3; ans%=MOD;
    ans = (ans+MOD)%MOD;

    cout << ans << endl;
    return;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}