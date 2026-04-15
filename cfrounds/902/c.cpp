//https://codeforces.com/contest/1876/problem/C

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
#define vi vector<int>
typedef long double ld;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> par(n+1);
    vector<int> badpar(n+1);
    vector<int> val(n+1, -1);
    queue<int> bfs;
    vector<bool> bfs_vis(n+1, false);
    rep(i, 1, n+1){
        int u; cin >> u;
        a[i] = u;
    }

    
    rep(i, 1, n+1) par[a[i]].push_back(i);
    rep(i, 1, n+1) badpar[i] = par[i].size();
    rep(i, 1, n+1) if(par[i].size() == 0){
        bfs.push(i);
        val[i] = 1; //white
        bfs_vis[i] = true; //agregado
    }

    while(!bfs.empty()){
        int bfssz = bfs.size();
        while(bfssz--){
            int u = bfs.front();
            bfs.pop();

            int v = a[u];
            badpar[v]--;

            if(bfs_vis[v]) continue;

            if(val[u] == 1){
                bfs.push(v);
                val[v] = 0;
                bfs_vis[v] = true;
                continue;
            }

            else if(badpar[v] == 0){
                bfs_vis[v] = true;
                bfs.push(v);
                bool white = true;
                for(auto p: par[v]){
                    if(val[p] == 1) white = false;
                }
                if(white) val[v] = 1;
                else val[v] = 0;
                continue;
            }
        }
    }

    
    vector<int> cycle;
    rep(i, 1, n+1){
        if(val[i] == -1){
            cycle.resize(0);
            int j = a[i];
            cycle.push_back(i);
            while(j != i){
                cycle.push_back(j);
                j = a[j];
            }
            

            if(cycle.size() %2  == 1){
                cout << -1 << endl; return;
            }

            rep(k, 0, cycle.size()) val[cycle[k]] = (k%2 == 0 ? 0 : 1);
        }
    }

    vector<int> res;
    rep(i, 1, n+1){
        if(val[i] == 1) res.push_back(a[i]);
    }
    cout << res.size() << endl;
    rep(i, 0, res.size()) cout << res[i] << ' ';
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}