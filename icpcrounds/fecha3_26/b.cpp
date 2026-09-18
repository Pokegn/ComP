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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

#define MOD 1000000007

ll fact[20001];
ll inv[20001];

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

ll binom(ll n, ll k) {
    if(k>n) return 0ll;
    ll facto = 1ll;
    for(ll i = n-k+1; i <= n; i++){
        facto *= i; facto%=MOD;
    }
    return (facto * inv[k]) % MOD;
}

void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> a;
    vector<ll> left(n), right(n);

    rep(i, 0, n){
        cin >> left[i];
        cin >> right[i];

    }
    
    rep(i, 1, n)  left[i] = max(left[i-1], left[i]);
    for(int i=n-1; i>=1; i--)  right[i-1] = min(right[i-1], right[i]);    
       
    rep(i, 0, n){
        if(left[i] > right[i]){
            cout << 0 << endl; return;
        }
    }

    rep(i, 0, n){ 
        a.push_back({left[i], -1}); // al reves para el sort
        a.push_back({right[i], +1});
    }
    sort(all(a));
    //hay sz-1 rangos, son de i a i+1
    
    vector<ll> asizes;
    vector<ll> aopen;
    vector<ll> aopened;
    vector<pair<ll, ll>> lr;
    
    ll opened = 1;
    ll open = 1;
    ll l = a[0].first;
    int szz = a.size();
    
    a[0].second *=-1;
    
    rep(i, 1, szz){
        a[i].second *= -1;
            if(a[i].first == a[i-1].first){
                if(a[i].second == a[i-1].second){
                    if(a[i].second == 1) opened++;
                    open+=a[i].second;
                    continue;
                }
                else{
                    lr.push_back({l, a[i].first});
                    asizes.push_back(a[i].first - l+1);
                    aopened.push_back(opened);
                    aopen.push_back(open);
                    open--;
                    l = a[i].first+1;
                    continue;
                }
            }
            if(a[i].second == 1){
                if(a[i].first-1 >= l){
                    lr.push_back({l, a[i].first-1});
                    asizes.push_back(a[i].first - l);
                    aopened.push_back(opened);
                    aopen.push_back(open);
                }
                l = a[i].first;
                open++;
                opened++;
                continue;
            }
            else{ // = -1
                lr.push_back({l, a[i].first});
                asizes.push_back(a[i].first - l+1);
                aopened.push_back(opened);
                aopen.push_back(open);
                open--;
                l = a[i].first+1;
                continue;
            }
        }
        szz = asizes.size();
        vector<ll> aclosed(szz);
        rep(i, 0, szz) aclosed[i] = aopened[i]-aopen[i];
        vector<vector<ll>> dp(szz+1, vector<ll>(n+1, 0)); //que pasa si en los primeros tres ponemos dos
    
    dp[0][0] = 1;
    
    
    rep(idx, 1, szz+1){
        int i = idx-1;
        ll biglimit = asizes[i];
        biglimit = min(biglimit, aopen[i]);
        
        vector<ll> binoms(601);
        rep(j, 0, 601) binoms[j] = binom(asizes[i], j);

        rep(k, 0, aopened[i]+1){ //o sea, k-insert
            ll limit = min(biglimit, (ll)k);

            rep(insert, 0, limit+1){
                int prev = k-insert;
                if(prev < aclosed[i]) continue;
                dp[idx][k] += (dp[idx-1][k-insert] * binoms[insert])%MOD;
                dp[idx][k] %= MOD;
            }
        }
    }
    
    cout << dp[szz][n]%MOD << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    fact[0] = 1; 
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 20001; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = fexp(fact[i], MOD - 2, MOD);
    }
    // cin >> t;
    while(t--) solve();
    return 0;
}