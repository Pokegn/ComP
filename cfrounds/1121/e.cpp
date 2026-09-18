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

int m = 5000;
vector<bool> is_prime(m+1, true);
vector<int> primes;
vector<int> minprime(m, -1);
vector<int> lim(3001);
vector<vector<ll>> llegar(3001, vector<ll>(3001));
#define MOD 998244353

void solve(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    sort(all(a), greater<ll>());
    vector<ll> sorted;
    ll ans = 0;
    rep(i, 0, n) ans+= a[i];
    // ans += a[0];
    sorted.push_back(a[0]);
    // sort(all(sorted));
    rep(i, 1, n){ //los que puedo hacer con los primeros i+1 o sea hasta i
        
        // ans += llegar[a[i]][a[i-1]];
        ll pot = 1;
        for(int j = i-1; j>=0; j--){
            ans += pot*llegar[a[i]][a[j]];
            ans%=MOD;
            // cout << pot << ' ' << llegar[a[i]][a[j]] << endl;
            pot*=2; pot%=MOD;
        }
        // sorted.push_back(a[i]);
        // sort(all(sorted));
    }
    cout << ans << endl;
    return; 
}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    is_prime[0] = is_prime[1] = false;
    minprime[1] = 1;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i] && (long long)i * i <= m) {
            for (int j = i * i; j <= m; j += i){
                minprime[i] = i;
                if(minprime[j] == -1) minprime[j] = i;
                is_prime[j] = false;
            }
        }
    }
    for(int i=2; i<=m; i++){
        if(is_prime[i]){
            primes.push_back(i);
            minprime[i] = i;
        } 
    }

    rep(i, 1, 3001){
        lim[i] = i*minprime[i];
    }

    // rep(i, 1, 10){
    //     cout << i << ' ' << minprime[i] << ' ' << lim[i] << endl;
    // }
    // return 0;

    rep(i, 1, 3001){
        llegar[1][i] = 1;
    }

    rep(i, 2, 3001){
        llegar[i][i] = i;
        rep(j, i+1, min(3001,lim[i])){
            llegar[i][j] = i;
        }
        rep(j, lim[i], 3001){
            llegar[i][j] = llegar[i-1][j-1];
        }
    }

    int t=1; 
    cin >> t;
    while(t--) solve();
    // cout <<"xd";
    return 0;
}