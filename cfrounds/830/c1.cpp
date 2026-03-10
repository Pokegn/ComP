#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    int l,r; cin >> l >> r;
    l--;
    r--;
    ll sum = 0;
    ll x = 0;
    rep(i, 0, n){
        sum+=a[i];
        x^=a[i];
    }
    ll ans = sum - x;
    if(sum == 0){
        cout << 1 << ' ' << 1 << endl;
        return;
    }

    ll izq = 0;
    ll der = n-1;
    ll izqx = x;
    ll derx = x;
    vector<pair<ll,ll>> xorizq, xorder;
    xorizq.push_back({x,0}), xorder.push_back({x,n-1});
    rep(i, 0, n){
        izq = i;
        if(a[i] == 0){
            xorizq.back().second++;
            continue;
        }
        if(a[i] == izqx-(izqx^a[i])){
            izqx^=a[i];
            xorizq.push_back({izqx,i+1});
        }
        else{
            break;
        }
    }

    for(int i = n-1; i>=0; i--){
        der = i;
        if(a[i] == 0){
            xorder.back().second--;
            continue;
        } 
        if(a[i] == derx-(derx^a[i])){
            derx^=a[i];
            xorder.push_back({derx,i-1});
        }
        else{
            break;
        }
    }

    for(auto &xd:xorizq) xd.first^=x;
    for(auto &xd:xorder) xd.first^=x;

    for(int i = 0; i < xorizq.size(); i++){ //0 es 0, 1 es 1
        for(int j = 0; j < xorder.size() && (xorder[j].second >= xorizq[i].second); j++){ //0 es n-1, 1 es n-2
            if((xorizq[i].first^xorder[j].first) == xorizq[i].first+xorder[j].first){
                if(xorder[j].second - xorizq[i].second < r-l){
                    r = xorder[j].second;
                    l = xorizq[i].second;
                }
            }
        }
    }
    cout << l+1 << ' ' << r+1 << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}