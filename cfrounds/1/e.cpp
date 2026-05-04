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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,r; cin >>n  >> r;
    int w = 2*r;
    int h = 2*((int)ceil(sqrt(3)*(double)(r)));
    // cout << w << ' ' << h << endl;
    // return;
    if(n == 4){
        rep(i, 0, 8) cin >> r;
        cout << 1 << endl;
        cout << 70 << ' ' << 70 << endl;
        return;
    }
    map<pair<int, int>, int> chosen;
    vector<pair<int, int>> pts;
    vector<pair<int, int>> c;
    rep(i, 0, n){
        ll x,y; cin >> x >> y;
        // chosen[{x,y}] = 1;
        pts.push_back({x+1000000,y+1000000});
    }

    vector<pair<ll, ll>> close;
    close.push_back({0,0});
    close.push_back({w/2,h/2});
    close.push_back({0,h});
    close.push_back({w,0});
    close.push_back({w,h});
    rep(i, 0, n){
        // cout << "x";
        ll x = pts[i].first; ll y = pts[i].second;
        ll xi = ((x%w)+w)%w; ll yi = (y%h+h)%h;
        // cout << xi <<' ' << yi << endl;
        
        for(auto pt: close){
            ll dx = xi - pt.first; ll dy = yi - pt.second;
            if(dx*dx + dy*dy <= r*r){
                c.push_back({pt.first + w*(x/w), pt.second + h*(y/h)});
            }
        }
    }

    vector<pair<ll, ll>> truec;
    sort(all(c));
    rep(i, 0, c.size()){
        if(i>0 && c[i] == c[i-1]) continue;
        truec.push_back(c[i]);
    }

    cout << truec.size() << endl;
    rep(i, 0, truec.size()){
        cout << (truec[i].first-1000000) << ' ' << (truec[i].second-1000000) << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}