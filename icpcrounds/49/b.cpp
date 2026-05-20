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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

int m = 300000;
vector<int> primes;
vector<bool> is_prime(m, true);

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n){
        rep(j,0,m) cin >> a[i][j];
    }

    int ans = 10000000;
    vector<vector<int>> to(n, vector<int>(m, 0));

    vector<int> tonext(200007);
    tonext[200007] = 0;
    for(int i = 200006; i>=0; i--){
        if(is_prime[i]) tonext[i] = 0;
        else{
            tonext[i] = tonext[i+1]+1;
        }
    }
    rep(i, 0, n){
        rep(j, 0, m){
            to[i][j] = tonext[a[i][j]];
        }
    }

    rep(i, 0, n){
        int temp = 0;
        rep(j, 0, m){
            temp += to[i][j];
        }
        ans = min(ans, temp);
    }

    rep(j, 0, m){
        int temp = 0;
        rep(i, 0, n){
            temp += to[i][j];
        }
        ans = min(ans, temp);
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= m; i++){
        if(is_prime[i] && (ll)i*i <= m){
            for(ll j = (ll)i*i; j < m; j+=i) is_prime[j] = false;
        }
    }

    while(t--) solve();
    return 0;
}