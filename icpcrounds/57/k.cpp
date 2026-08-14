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
    int n, m; cin >> n >> m;
    vector<vector<int>> grafo(n);
    rep(i, 0, m){
        int u,v; cin >> u >> v; u--; v--;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vector<pair<int, int>> rangos;
    queue<int> bfs;
    vector<bool> bfs_vis(n, false);
    rep(i, 0, n){
        if(bfs_vis[i]) continue;
        bfs_vis[i] = true;
        int mini = i;
        int maxi = i;
        bfs.push(i);
        while(!bfs.empty()){
            int bfssz = bfs.size();
            while(bfssz--){
                int u = bfs.front();
                bfs.pop();
                
                for(auto v : grafo[u]){
                    if(!bfs_vis[v]){
                        bfs.push(v);
                        bfs_vis[v] = true;
                        maxi = max(maxi, v);
                        mini = min(mini, v);
                    }
                }
            }
        }
        rangos.push_back({mini, maxi});
    }

    //for(auto p: rangos) cout << p.fi+1 << ' ' << p.se+1 << endl;
    minheap<pair<int, int>> rgs; for(auto p: rangos) rgs.push(p);
    // return;
    int ans = 0;
    while(rgs.size() > 1){
        auto r1 = rgs.top(); rgs.pop();
        auto r2 = rgs.top(); rgs.pop();

        pair<int, int> add = r2;
        if(r2.fi < r1.se){
            ans++;
            add = {min(r1.fi, r2.fi), max(r1.se, r2.se)};
        }
        rgs.push(add);
    }
    cout << ans << endl;
    return;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}