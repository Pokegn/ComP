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

void solve(){
    ll n,p; cin >> n >> p;
    vlli a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    } 
    vector<ll>potrep(1e6+1000, 0);
    for(int i=0; i<n; i++){
        potrep[a[i]]++;
    }
    if(p == 1){
        cout << n%2 << endl;
        return;
    }
    
    ll maxval = -1;
    for(ll i=1e6+998; i>=0; i--){
        if(potrep[i]%2 != 0){
            maxval = max(maxval, i);
        }
    }

    for(int i=0; i<1e6+999; i++){
        potrep[i+1] += potrep[i]/p;
        potrep[i]%=p;
    }

    vlli pot(1e6+1000);
    pot[0] = 1;
    for(int i=1; i<=(1e6+999); i++){
        pot[i] = pot[i-1]*p;
        pot[i]%=MOD;
    }

    if(maxval == -1){
        cout << 0 << endl;
        return;
    }
    //maxval tiene el mayor indice
    cout << maxval << endl;
    ll ans = 0;
    for(int i=0; i<1e6+999; i++){
        if(i>maxval) continue;
        if(i == maxval){
            ans+=pot[i];
            ans%=MOD;
        }
        else{
            ans-=pot[i]*potrep[i];
            ans%=MOD;
        }
    }
    ans = (ans%MOD+MOD)%MOD;
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}