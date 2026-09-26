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
#define MOD 1000000007

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

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll m = (ll)sz(s);

    vector<ll> rots; //todos los que tengo que checar atras ademas de mi coso

    rep(i, 1, m){
        string firsti = "", lasti = "";
        
        rep(j, 0, i){
            firsti+=s[j];
            lasti+=s[m-i+j];
        }
        
        if(firsti == lasti) rots.push_back(i);
    }
    
    string r;
    // rep(i, 1, m){
    //     r = s;
    //     rotate(r.begin(), r.end() - i, r.end()); //rotar uno a la derecha
    //     // if(r == s) cout << "AA " << i << endl;
    // }

    // for(auto xd: rots) cout << xd << ' ';
    // cout << endl;

    vector<ll> countfinal(n, 0); //en cuantos la primera vez que hay un s es acabando hasta i
    vector<ll> countnunca(n, 0); //en cuantos no hay ningun s de 0 a i
    ll tot = 0;

    //para que este por primera vez acabando en i, entonces
    //los primeros i-m no tienen nada
    //y luego le quito los que tienen en alguno de rot
    //pero tiene que ser en alguno

    rep(i, 0, n){
        tot = fexp(26, n, MOD);
        if(i-m < -1){
            countfinal[i] = 0;
        }
        else{
            if(i-m == -1) countfinal[i] = 1;
            else{
                countfinal[i] = countnunca[i-m];
            }
        }

        for(auto j: rots){ //en lugar de checar el i-m checo el i-m+j
            if(i-2*m+j == -1) countfinal[i] --;
            if(i-2*m+j >= 0) countfinal[i] -= countfinal[i-m+j];
            countfinal[i]%=MOD;
            countfinal[i] = (countfinal[i] + MOD)%MOD;
        }

        if(i == 0) countnunca[i] = 26 - countfinal[0];
        else countnunca[i] = ((countnunca[i-1]*26 - countfinal[i])%MOD + MOD)%MOD;
    }

    ll ans = 0;
    rep(i, 0, n){
        countfinal[i] = (countfinal[i]*fexp(26, n-i-1, MOD))%MOD;
        // cout << countfinal[i] << ' ' << countnunca[i] << endl;
        ans += countfinal[i]; ans%=MOD;
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}