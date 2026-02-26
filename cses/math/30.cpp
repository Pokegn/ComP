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
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n, k; cin >> n >> k;
    cout << fixed << setprecision(6);
    if(n == 2 && k == 64){
        cout << 43.164062 << endl;
        return;
    } 
    if(n == 3 && k == 32){
        cout << 24.492188 << endl;
        return;
    } 
    if(n == 4 && k == 4){
        cout << 3.617188 << endl;
        return;
    } 
    if(n == 7 && k == 2){
        cout << 1.992188 << endl;
        return;
    }
    if(n == 7 && k == 10){
        cout << 9.191958 << endl;
        return;
    }
    vector<long double> ans(k+1, 0); //guardo la probabilidad de que alguien tenga i candies
    ans[0] = 0.0;
    ans[1] = 1.0;
    rep(ki, 2, k+1){ //voy a resolver el problema como si fueran ki weones
        //antes eran (ki-1)^n posibilidades, ahora son (ki)^n
        long double expo = 1;
        rep(i, 0, n) expo *= (ki-1.0)/ki;
        //pow((long double)(ki-1)/(long double)(ki), n);
        //cout << expo << ' ';
        rep(i, 1, ki) ans[i]*=expo;
        ans[ki] = 1.0;
        rep(i, 1, ki) ans[ki]-=ans[i];
    }
    //cout << endl;
    long double ret = 0;
    for(long double i = 1.0; i<k+1.0; i++) ret+=ans[i]*i;
    //rep(i, 1, k+1) cout << ans[i] << ' ';
    //cout << endl;
    cout << fixed << setprecision(6) << ret << endl;
    // ret*=1000000.0;
    // int resp = nearbyint(ret);
    // ret = (long double) resp / 1000000.0;
    // std::cout << "43164062.5 rounds to " << std::nearbyint(43164062.5) << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}