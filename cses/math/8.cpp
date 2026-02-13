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

ll INF = 1e18;

vector<ll> pottoi;

ll lowbit(ll a){
    ll xd = a & (a-1);
    ll bit = a^xd;
    return pottoi[bit];
}

void solve(){
    INF+=10;
    ll n; cin >> n;
    int k; cin >> k;
    ll bitmax = 1<<k;
    pottoi = vector<ll>(1000020);
    for(int i=0; i<k; i++){
        pottoi[1<<i] = i;
    }
    pottoi[0] = 0;
    vector<ll> p(k); for(int i=0; i<k; i++) cin >> p[i];
    
    vector<ll> pprod(10000020,0);
    pprod[0] = 1;


    for(int i=1;i<bitmax; i++){
        ll idx = lowbit(i);
        if((long double)(pprod[i&(i-1)]) > (long double)n/(long double)p[idx]) pprod[i] = INF;
        else pprod[i] = pprod[i&(i-1)]*p[idx];
    }

    ll ret = 0;

    for(int i=1; i<bitmax; i++){
        ll count = __popcount(i);
        count = count%2;
        if(count == 0){
            ret-=n/pprod[i];
        }
        else{
            ret+=n/pprod[i];
        }
    }

    cout << ret << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}