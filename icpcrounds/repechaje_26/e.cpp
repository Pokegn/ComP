#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
#define MOD 998244353

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
} //llamas fexp(x, m-2, m)

void solve(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> pots(n);

    rep(i, 0, n){
        //aqui las cuentas para cuantas formas de elegir 2^i numeros que esten ordenados
    }

    rep(i, 0, n){
        pots[i] = fexp(2, i, MOD);
        a[i]*=fexp(pots[i], MOD-2, MOD);
        a[i]%=MOD;
    }

    //a[i] tiene la probabilidad de que esten ordenados en el i-esimo paso

    rep(i, 0, n){
        
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}