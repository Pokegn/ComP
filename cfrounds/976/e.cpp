#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define MOD 1000000007
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}\

ll inverso;

long long fexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    vector<ll> probs(1024, 0);
    probs[0] = 1;
    vector<ll> newprobs(1024);
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    vector<ll> p(n); rep(i, 0, n) cin >> p[i];
    rep(i, 0, n){
        rep(j, 0, 1024){
            newprobs[j] = (probs[j]*(10000-p[i]) %MOD)*inverso; newprobs[j]%=MOD;
            newprobs[j] += (p[i]*inverso % MOD)*probs[((a[i])^(j))]%MOD;
        }
        swap(probs, newprobs);
    }
    ll ans = 0;
    rep(i, 0, 1024){
        //if(probs[i]!=0) cout << i << ' ' << probs[i] << endl;
        ll sum = i*i % MOD;
        ans += (probs[i]*sum%MOD); ans%=MOD;
    }
    cout << (ans+MOD)%MOD << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    inverso = fexp(10000, MOD-2, MOD);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}