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

map<ll, ll> respuesta;

vlli divisores(0);

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

void coso(ll suma){ // formas de hacer una seq cualquiera es 2^(y-1)
    ll pot2 = fexp(2, suma-1, MOD);
    if(suma == 1){
        respuesta[suma] = 1;
        return;
    }
    ll ans = pot2;
    for(int i=0; divisores[i]<suma; i++){
        if(suma%divisores[i] == 0){
            ans-= respuesta[divisores[i]];
            ans%=MOD;
            ans += MOD;
            ans%=MOD;
        }
    }
    
    respuesta[suma] = ans;
    return;
}

void solve(){
    ll x,y; cin >> x >> y;
    if(x>y){
        cout << 0 << endl;
        return;
    }
    if(x==y){
        cout << 1 << endl;
        return;
    }
    if(x!=1){
        if(y%x!=0){
            cout << 0 << endl;
            return;
        }
        y/=x;
        x/=x;
    }
    for(int i=1; i*i<=y; i++){
        if(y%i == 0){
            divisores.push_back(i);
            if(i*i<y){
                divisores.push_back(y/i);
            }
        } 
    }
    sort(divisores.begin(), divisores.end());

    for(int i=0; i<divisores.size(); i++){
        coso(divisores[i]); //ya tengo hechos todos los anteriores que necesito
    }

    // for(auto k: divisores){
    //     cout << k << ' ' << respuesta[k] << endl;
    // }
    cout << (respuesta[y]%MOD+MOD)%MOD << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}