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

vector<vector<ll>> divs;
vector<ll> ans;
ll m;

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

void getdivs(ll n){
    if(divs[n].size()>0) return;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            divs[n].push_back(i);
            if(i!=n/i) divs[n].push_back(n/i);
        }
    }
}

void fill(ll n){
    if(n == 1){
        ans[n] = m;
        return;
    }

    ll ret = fexp(m, n, MOD);
    for(auto d: divs[n]){
        if(d == n) continue;
        ret-= d*ans[d];
        ret%=MOD;
    }
    ret *= fexp(n, MOD-2, MOD); ret%=MOD;
    ret = (ret+MOD)%MOD;
    ans[n] = ret;
    return;
}

void solve(){
    divs = vector<vector<ll>> (1e6+1, vector<ll>(0));
    ans = vector<ll> (1e6+1, -1);
    ll n; cin >> n >> m;
    getdivs(n);
    for(auto x: divs[n]) getdivs(x); //ya tengo los divisores de todos los divisores de n

    sort(divs[n].begin(), divs[n].end());
    for(auto d: divs[n]) fill(d);

    // for(auto d: divs[n]){
    //     cout << d << ' ' << ans[d] << endl;
    // }
    ll answer = 0;
    for(auto d: divs[n]){
        answer+= ans[d]; answer%=MOD;
    }
    cout << answer << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}