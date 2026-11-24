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

void solve(){
    multiset<ll> ms;
    ll n; cin >> n;
    vector<pii> a;
    vector<int> contains(n, 0), is_contained(n, 0);
    vector<vi> endpoints;
    rep(i,0,n){
        pii x; cin >> x.fi >> x.se;
        a.push_back(x);
        endpoints.push_back({x.fi, 1, i});
        endpoints.push_back({x.se, -1, -i});
    }

    sort(all(endpoints));
    priority_queue<int> last_start_closed;
    priority_queue<int> farthest_close;

    for(auto e: endpoints){
        int idx;
        if(e[1] == 1){
            idx = e[2];
            if(!farthest_close.empty()){
                int topo = farthest_close.top();
                if(topo <= a[idx].se){
                    is_contained[idx] = 1;
                }
            }
            farthest_close.push(a[idx].se);
        }
        else{
            idx = -e[2];
            if(!last_start_closed.empty()){
                int topo = last_start_closed.top();
                if(topo >= a[idx].fi){
                    contains[idx] = 1;
                }
            }
            last_start_closed.push(a[idx].fi);
        }
    }
    
    rep(i,0,n) std::cout << contains[i] << ' ';
    std::cout << endl;
    rep(i,0,n) std::cout << is_contained[i] << ' ';
    std::cout << endl;
    
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}