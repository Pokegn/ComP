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
    int n; cin >> n;
    vector<ll> x(n), y(n), z(n), r(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> z[i] >> r[i];
    }
 
    vector<vector<ll>> grafo(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if((x[i]-x[j])*(x[i]-x[j])
            +(y[i]-y[j])*(y[i]-y[j])
            +(z[i]-z[j])*(z[i]-z[j]) < (r[i]+r[j])*(r[i]+r[j])){
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }

    vector<bool> vis(n, false);
    while(true){
        ll rad = -1;
        ll idx = -1;
        for(int i=0; i<n; i++){
            if(!vis[i] && r[i] > rad){
                idx = i;
                rad = r[i];
            }
        }
        if(rad == -1) break;
        
        vis[idx] = true;
        for()
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}