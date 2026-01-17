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

ll x1,y1,x2,y2; 

bool reachable(ll x, ll y){
    ll b = (y1*x)-(x1*y);
    b/=(x2*y1-x1*y2);
    ll a = (y2*x)-(x2*y);
    a/=(x1*y2-x2*y1);

    if(x == a*x1+b*x2 && y == a*y1+b*y2) return 1;
    return 0;
}

void solve(){
    ll n; cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x,y;
    if(x1 == 0 && x2 == 0){
        cout << "NO" << endl;
        return;
    }
    if(y1 == 0 && y2 == 0){
        cout << "NO" << endl;
        return;
    }
    y = ((y1*x2)-(x1*y2))/__gcd(x1, x2);
    x = ((y1*x2)-(x1*y2))/__gcd(y1, y2);
    x = abs(x);
    y = abs(y);
    cout << "xy " << x << ' ' << y  << endl;
    if(n < x*y || x*y==0){
        cout << "NO" << endl;
        return;
    }
    
    vlli ansx;
    vlli ansy;

    
    for(ll i=0; i<x; i++){
        if(reachable(i, 0)) ansx.push_back(i);
    }
    for(ll j=1; j<y; j++){

    }
    for(auto k: ansx){

    }

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << i << ' ' << j << endl;
        }
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}