#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ll m = 1000;
vector<bool> is_prime(m+1, true);
vector<ll> primes;

ll lcm(ll a, ll b){
    ll g = __gcd(a,b);
    return (a*b)/g;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<ll> c(n);
    c[0] = __gcd(a[0], a[1]);
    c[n-1] = __gcd(a[n-1], a[n-2]);
    rep(i, 1, n-1){
        c[i] = lcm(__gcd(a[i], a[i-1]), __gcd(a[i], a[i+1]));
    }

    //si el lcm es mas de b[i] pues nunca sera distinto de a[i]             tipo 1
    //si no, y c[i] es a[i], tiene que aumentar                             tipo 2
    //si no, entonces c[i] < a[i] y este ya es feliz                        tipo 3

    vector<ll> tipo(n, 0);

    rep(i, 0, n){
        if(c[i] > b[i]){
            c[i] = a[i];
            tipo[i] = 1;
            continue;
        }
        if(c[i] == a[i]){
            tipo[i] = 2;
            continue;
        }
        else{
            tipo[i] = 3;
            continue;
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(21, 0));
    if(tipo[0] == 1){
        rep(j, 0, 21) dp[0][j] = 0;
    }
    if(tipo[0] == 2){
        rep(j, 1, 21){
            if(c[0]*primes[j] > b[0]) continue;
            if(__gcd(c[0]*primes[j], c[1]) != __gcd(a[0], a[1])) continue;
            dp[0][j] = 1;
        }
    }
    if(tipo[0] == 3){
        rep(j, 0, 21) dp[0][j] = 1;
    }


    rep(i, 1, n){
        if(tipo[i] == 1){
            ll maxi = 0;
            rep(j, 0, 21){
                maxi = max(maxi, dp[i-1][j]);
            }
            dp[i][0] = maxi;
        }


        if(tipo[i] == 2){
            //j = 0
            if(i+1<n && __gcd(c[i], c[i+1]) != __gcd(a[i], a[i+1])) continue; //apto
                if(__gcd(c[i], c[i-1]) != __gcd(a[i], a[i-1])) continue;
                ll maxii = dp[i-1][0];
                rep(k, 0, 21){
                    if(__gcd(c[i], c[i-1]*primes[k]) != __gcd(a[i], a[i-1])) continue;
                    maxii = max(maxii, dp[i-1][k]);
                }
                dp[i][0] = maxii;

            rep(j, 1, 21){ //quiero calcular dp[i][j]
                if(i+1<n && __gcd(c[i]*primes[j], c[i+1]) != __gcd(a[i], a[i+1])) continue; //apto
                if(__gcd(c[i]*primes[j], c[i-1]) != __gcd(a[i], a[i-1])) continue;
                if(c[i]*primes[j] > b[i]) continue;
                ll maxi = dp[i-1][0]+1;
                rep(k, 0, 21){
                    if(__gcd(c[i]*primes[j], c[i-1]*primes[k]) != __gcd(a[i], a[i-1])) continue;
                    maxi = max(maxi, dp[i-1][k]+1);
                }
                dp[i][j] = maxi;
            }
        }


        if(tipo[i] == 3){
            ll maxi = 0;
            rep(j, 0, 21){
                maxi = max(maxi, dp[i-1][j]);
            }
            dp[i][0] = maxi+1;
        }
    }

    // rep(i, 0, n){
    //     cout << tipo[i] << ' ' << i << ": ";
    //     rep(j, 0, 21) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    ll ans = 0;
    rep(i, 0, 21){
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i] && (long long)i * i <= m) {
            for (int j = i * i; j <= m; j += i)
                is_prime[j] = false;
        }
    }
    primes.push_back(1);
    for(int i=2; i<=m; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}