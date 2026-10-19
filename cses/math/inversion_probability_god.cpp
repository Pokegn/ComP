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
 
int m = 200;
vector<bool> is_prime(m+1, true);
vector<ll> primes;

vector<ll> r;
vector<pair<ll, ll>> frac;
int n;

ll vp(ll a, ll p){
    ll ans = 0;
    while(a%p == 0){
        ans++;
        a/=p;
    }
    return ans;
}
 
pair<ll, ll> expected(int i, int j){
    ll x = r[i], y = r[j];
    if(x <= y){
        return {x-1, 2*y};
    }
    else{
        return {2*x-y-1, 2*x};
    }
}

ll numptot(ll num, ll den, ll maxpot){ //saca la 
    ll g;
    ll ans = num;
    for(auto x: r){
        g = __gcd(x, den); den/=g; x/=g;
        ans *= x;
        ans %= maxpot;
    }
    return ans;
}

void solve(){
    cin >> n;
    r = vector<ll>(n); rep(i, 0, n) cin >> r[i];

    rep(i, 0, n){
        rep(j, i+1, n){
            frac.push_back(expected(i,j));
        }
    }

    bool flag = true;

    for(auto f: frac){
        ll num = f.fi, den = f.se;
        cout << "Fraction(" << num << '/' << den << "), ";
    }
    cout << endl;
    return;

    for(auto p: primes){
        ll totpot = 0;
        rep(i, 0, n) totpot += vp(r[i], p);
        
        ll maxpot = 1, maxpot_exp = 0;
        while(maxpot <= 2000000){ maxpot *= p; maxpot_exp++; } 

        ll ppot = maxpot;
        if(p !=2 && p != 5){
            if(maxpot_exp > totpot){
                ppot = 1;
                rep(i, 0, totpot) ppot*=p;
            }
        }
        
        ll pval = 0;

        for(auto f: frac){
            ll num = f.fi, den = f.se;
            pval += numptot(num, den, maxpot);
            pval %= ppot;
        }

        cout << p << ' ' << pval << ' ' << ppot << endl;
        if(p == 2){
            if(pval%128 != 0){
                flag = false;
            }
            continue;
        }
        if(p == 5){
            if(pval%15625 != 0){
                flag = false;
            }
            continue;
        }
        if(pval%ppot != 0){
            flag = false;
        }
    }

    if(flag) cout << "caso raro" << endl;
    else cout << "caso normal" << endl;

    ld ans = 0;
    for(auto f: frac){
        ld add = (long double)f.fi/(long double)f.se;
        ans += add;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i] && (long long)i * i <= m) {
            for (int j = i * i; j <= m; j += i){
                is_prime[j] = false;
            }
        }
    }

    for(int i=2; i<=100; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    //cin >> t;
    while(t--) solve();
    return 0;
}