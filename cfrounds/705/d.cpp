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
#define MOD 1000000007

vector<ll> primes;
vector<bool> is_prime(200001, true);
vector<vector<ll>> primosdiv(200001);
map<ll, ll> ppot;//primos que dividen a cada numero
map<ll, ll> idxpot;//las potencias que tiene cada indice
vector<vector<ll>> idxprimos;
ll res;
// map<ll, ll> mins;
map<ll, multiset<ll>> sett;

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

ll encode(ll a, ll b) {
    return (a << 30) ^ b; // careful with limits
}

void fillppot(){
    for(ll i = 0; i<primes.size(); i++){
        ll pot = primes[i];
        for(ll j = primes[i]; j<200001; j+=primes[i]){
            ppot[encode(j,primes[i])]++;
            primosdiv[j].push_back(primes[i]);
        }
        pot*=primes[i];
        while(pot < 200001){
            for(ll j = pot; j<200001; j+=pot){
                ppot[encode(j,primes[i])]++;
            }
            pot*=primes[i];
        }
    }
    return;
}

void inc(ll idx, ll x){
    for(auto p: primosdiv[x]){ //a add[idx, p] le agrego ppot[x, p]
        if(idxpot[encode(idx, p)] == 0){
            idxprimos[idx].push_back(p); //si no lo dividia y ahora si pos lo agrego
        } 
        else{
            auto it = sett[p].find(idxpot[encode(idx, p)]);
            sett[p].erase(it);
        }
        idxpot[encode(idx, p)] += ppot[encode(x,p)];
        sett[p].insert(idxpot[encode(idx, p)]);
    }
}

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    idxprimos.resize(n);
    // for(auto p:primes) mins[p] = 100000000;
    
    res = 1;
    rep(i, 0, n){
        idxprimos[i] = primosdiv[a[i]];
        for(auto p: primosdiv[a[i]]){
            idxpot[encode(i, p)] = ppot[encode(a[i],p)];
            sett[p].insert(idxpot[encode(i,p)]);
        }
    }
    
    for(auto p:primes){
        if(sett[p].size() < n) continue;
        res*= fexp(p, *sett[p].begin(), MOD); res%=MOD;
    }
    // cout << res << endl;
    
    rep(query, 0, q){
        //cout << "query: " << query << endl;
        ll i, x; cin >> i >> x;
        unordered_map <ll, ll> antesmins;
        for(auto p:primosdiv[x]){
            if(sett[p].size() < n) antesmins[p] = 0;
            else antesmins[p] = *sett[p].begin();
        } 
        i--;
        inc(i, x);

        
        for(auto p:primosdiv[x]){
            if(sett[p].size() < n) continue;
            ll antes = antesmins[p];
            ll mini = 100000000;
            //cout << "primo: " << p << ' ';
            mini = *sett[p].begin();
            //cout << endl;
            ll expo = fexp(p, mini-antes, MOD);
            res*=expo; res%=MOD;
        }

        cout << res << endl;
        //cout << endl;
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 

    is_prime[0] = is_prime[1] = false;
    rep(i, 2, 200001){
        if(is_prime[i]){
            primes.push_back(i);
            if((ll)i*i <= 200001){
                for(ll j = i*i; j<200001; j+=i){
                    is_prime[j] = false;
                }
            }
        } 
    }
    fillppot();
    // if(is_prime[10009]) cout <<"xd";
    //cout << primes.size() << endl;

    //cin >> t;
    while(t--) solve();
    return 0;
}