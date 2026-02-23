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

vector<ll> fact(2e6+1, 1);

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

ll comb(ll a, ll b){
    if(b>a) return 0;
    ll ans = fact[a];
    ans *= fexp(fact[b], MOD-2, MOD); ans%=MOD;
    ans *= fexp(fact[a-b], MOD-2, MOD); ans%=MOD;
    return ans;
}

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    ll sz = s.length();
    ll left = 0;
    ll right = 0;
    
    for(auto c:s){
        if(c == '(') left++;
        else right++;
        if(left-right<0){
            cout << 0 << endl;
            return;
        }
    }

    if(n%2 == 1){
        cout << 0 << endl;
        return;
    }

    ll x = n/2-left;
    ll y = n/2-right;
    //cout << x << ' ' << y << endl;
    if((x == y) && (x == 0)){
        cout << 1 << endl;
        return;
    }
    if(x<0 || y<0){
        cout << 0 << endl;
        return;
    }

    ll ans;
    ans = comb(x+y, y); ans%=MOD;
    ans -= comb(x+y, y+1); ans%=MOD;
    cout << (ans+MOD)%MOD << endl;
    return;


}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;

    for(ll i=2; i<=2000000; i++){
        fact[i] = (i*fact[i-1])%MOD;
    }

    while(t--) solve();
    return 0;
}