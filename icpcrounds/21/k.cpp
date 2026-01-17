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

void solve(){
    ll n; cin >> n;
    ll s; cin >> s;
    vector<ll> xi, yi, xf, yf;
    ll xd;
    xi.push_back(0);
    xf.push_back(0);
    yi.push_back(0);
    yf.push_back(0);
    for(int i=0; i<n; i++){
        cin >> xd;
        xi.push_back(xd);
        cin >> xd;
        yi.push_back(xd);
        cin >> xd;
        xf.push_back(xd);
        cin >> xd;
        yf.push_back(xd);
    }

    ll sxi = 0, syi = 0, sxf = 0, syf = 0;
    for(int i=1; i<=n; i++){
        sxi+=xi[i];
        syi+=yi[i];
        sxf+=xf[i];
        syf+=yf[i];
    }

    ll godx = sxf - sxi + 2*xi[s];
    godx/=2;
    ll gody = syf - syi + 2*yi[s];
    gody/=2;

    for(int i=1; i<=n; i++){
        if(xf[i] == godx && yf[i] == gody){
            cout << i << endl;
            return;
        }
    }
    cout << "quepedo" << endl;
    return;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}