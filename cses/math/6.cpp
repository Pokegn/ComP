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

ll rang(ll a, ll b){
    return b-a+1;
}

void solve(){
    //quiero n/i * i , o n - n%i para todos de 1 a n.
    ll n; cin >> n;
    ll ans = 0;
    if(n<=1000){
        for(ll i=1; i<=n; i++){
            ans+= n - n%i;
            ans%=MOD;
        }
        cout << ans << endl;
        return;
    }

    ans = (n%MOD)*(n%MOD);
    ans%=MOD;

    vector<ll> breakpoints;
    ll maxbp = 0;
    for(ll i=1; i*i<=n; i++){
        breakpoints.push_back(n/i);
        maxbp = i;
    }
     
    // for(auto x: breakpoints) cout << x << ' ' << endl;
    // return;

    ll sz = breakpoints.size();
    for(ll i=0; i<sz-1; i++){
        ll rango = rang(breakpoints[i+1]+1, breakpoints[i]);
        //cout << rango << endl;
        rango%=MOD;

        ll quita;
        quita = (n%(i+1))*rango; quita%=MOD;
        ans-=quita; ans%=MOD;

        quita = rango*(rango-1)/2; quita%=MOD; 
        quita*=i+1; quita%=MOD;
        ans-=quita; ans%=MOD;        
    } //ya tengo cubiertos todos tales que k> n/maxbp

    for(ll i=1; i<=n/maxbp; i++){
        ans-= n%i;
        ans%=MOD; 
    }

    ans = (ans+MOD)%MOD;

    cout << ans << endl;
    //return;

    // for(ll i=1; i<=n; i++){
    //     cout << i << ' ' << n%i << endl;
    // }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}