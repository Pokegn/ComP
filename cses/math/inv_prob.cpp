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

pair<ll, ll> expected(int i, int j){
    ll x = r[i], y = r[j];
    if(x <= y){
        return {x-1, 2*y};
    }
    else{
        return {2*x-y-1, 2*x};
    }
}

vector<ll> factoriza(ll x){
    vector<ll> xpow(sz(primes), 0);
    rep(i, 0, sz(primes)){
        ll p = primes[i];
        while(x%p == 0){
            xpow[i]++;
            x/=p;
        }
    }
    return xpow;
}

vi multiply(vi a, vi b){
    if(a == vi{0} || b == vi{0}) return vi{0};
    int n = sz(a), m = sz(b);
    reverse(all(a));
    reverse(all(b));

    vi ans(m+n, 0);
    rep(i, 0, n){
        rep(j, 0, m){
            ans[i+j] += a[i]*b[j];
        }
    }

    rep(i, 0, m+n-1){
        ans[i+1] += ans[i]/10;
        ans[i] %= 10;
    }

    reverse(all(ans));
    if(ans[0] == 0){
        vi anss;
        rep(i, 1, m+n) anss.push_back(ans[i]);
        swap(ans, anss);
    }
    return ans;
}

vi lltovi(ll n){
    if(n == 0){
        return (vi){0};
    }
    
    vi ret;
    while(n>0){
        ret.push_back(n%10);
        n/=10;
    }
    reverse(all(ret));
    return ret;
}

vi add(vi a, vi b){
    reverse(all(a));
    reverse(all(b));

    int maxsize = max(sz(a), sz(b)) + 1;
    vi ret(maxsize);
    a.resize(maxsize); b.resize(maxsize);

    rep(i, 0, maxsize){
        ret[i] += a[i] + b[i];
    }

    rep(i, 0, maxsize-1){
        ret[i+1] += ret[i]/10;
        ret[i] %= 10;
    }

    reverse(all(ret));

    vi anss;
    int idx = 0;
    while(ret[idx] == 0) idx++;
    rep(i, idx, maxsize) anss.push_back(ret[i]);
    swap(ret, anss);
    return ret;
}

bool morethan(vi a, vi b){ // a > b?
    if(sz(a) > sz(b)) return true;
    if(sz(a) < sz(b)) return false;
    rep(i, 0, sz(a)){
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return true;
}

void solve(){
    cin >> n;
    r = vector<ll>(n); rep(i, 0, n) cin >> r[i];

    rep(i, 0, n){ //llena frac
        rep(j, i+1, n){
            frac.push_back(expected(i,j));
        }
    }

    vector<ll> denpow(sz(primes), 0);
    rep(i, 1, 100){ //factorizacion del mcd de 1 a 100
        ll x = i;
        vector<ll> xpow = factoriza(x);
        rep(j, 0, sz(primes)){
            denpow[j] = max(denpow[j], xpow[j]);
        }
    }
    denpow[0] = 7;
    
    vi den_ans = {1};
    rep(i, 0, sz(primes)){
        vi p = lltovi(primes[i]);
        rep(j, 0, denpow[i]) den_ans = multiply(den_ans, p);
    }

    vi num_ans = {0};
    for(auto f: frac){
        vi num = lltovi(f.fi);
        vector<ll> factden = factoriza(f.se);
        rep(i, 0, sz(primes)){
            rep(j, 0, denpow[i]-factden[i]){
                num = multiply(num, lltovi(primes[i]));
            }
        }
        num_ans = add(num_ans, num);
    }

    //ya tengo la respuesta del numerador en num_ans
    //ahora quiero la respuesta de verdad

    num_ans = multiply(num_ans, vi({1, 0, 0, 0, 0, 0, 0, 0}));
    vector<vi> den_mult(8);
    den_mult[0] = multiply(den_ans, vi({1}));
    den_mult[1] = multiply(den_ans, vi({1,0}));
    den_mult[2] = multiply(den_ans, vi({1,0,0}));
    den_mult[3] = multiply(den_ans, vi({1,0,0,0}));
    den_mult[4] = multiply(den_ans, vi({1,0,0,0,0}));
    den_mult[5] = multiply(den_ans, vi({1,0,0,0,0,0}));
    den_mult[6] = multiply(den_ans, vi({1,0,0,0,0,0,0}));
    den_mult[7] = multiply(den_ans, vi({1,0,0,0,0,0,0,0}));

    vi curr = {0};
    vector<ll> digitos(8);
    rep(i, 0, 8){
        while(morethan(num_ans, add(curr, den_mult[7-i]))){
            digitos[i]++;
            curr = add(curr, den_mult[7-i]);
        }
    }

    ll esta_va_para_todas_las_mujeres_que_hacen_vino = 0;
    rep(i, 0, 8){
        ll pot = 1; rep(j, 0, 7-i) pot *= 10;
        esta_va_para_todas_las_mujeres_que_hacen_vino += digitos[i]*pot;
    }
    
    //si si pues ya porque roundeo half to even
    if(curr == num_ans && digitos[7] == 5){ //ES EXACTAMENTE EL CASO
        if(digitos[6]%2 == 0){
            esta_va_para_todas_las_mujeres_que_hacen_vino -= 5;
        }
        else{
            esta_va_para_todas_las_mujeres_que_hacen_vino += 5;
        }
    }
    else{
        if(digitos[7] >= 5){
            esta_va_para_todas_las_mujeres_que_hacen_vino+=10;
        }
    }

    esta_va_para_todas_las_mujeres_que_hacen_vino/=10;
    rep(i, 0, 7){
        ll pot = 1; rep(j, 0, 6-i) pot *= 10;
        cout << esta_va_para_todas_las_mujeres_que_hacen_vino/pot;
        esta_va_para_todas_las_mujeres_que_hacen_vino%=pot;
        if(i == 0) cout << '.';
    }
    cout << endl;
    
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