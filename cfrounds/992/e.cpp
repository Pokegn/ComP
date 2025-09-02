#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, q; cin >> n >> q;
    vvlli grafo(n+1, vlli(0));

    vlli valb(n+1, 0);
    vlli valn(n+1, 0);
    vector<lli> color(n+1, 1);
    vlli vecinos(n+1, 0);

    forn(i, 0, n-1){
        lli u,v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    queue<lli> bfs; bfs.push(1);
    vector<bool> bfs_vis(n+1, false); bfs_vis[1] = true;
    valb[1] = 0; color[1] = 1;
    while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            lli v = bfs.front();
            bfs.pop();

            for(auto u : grafo[v]){
                vecinos[v]++;
                if(!bfs_vis[u]){
                    bfs_vis[u] = true;
                    bfs.push(u);
                    color[u] = color[v]*(-1);
                }
            }
        }
    }
    
    vvlli nvec(n+1, vlli(0));
    vvlli bvec(n+1, vlli(0));
    vecinos[1] = 1;

    bfs.push(1);
    bfs_vis = vector<bool>(n+1, false); bfs_vis[1] = true;
    while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            lli v = bfs.front();
            bfs.pop();

            for(auto u : grafo[v]){
                if(!bfs_vis[u]){
                    bfs_vis[u] = true;
                    bfs.push(u);

                    for(auto x : nvec[v]){
                        nvec[u].push_back(x);
                    }
                    for(auto x : bvec[v]){
                        bvec[u].push_back(x);
                    }

                    if(color[u] == -1){ //n
                        nvec[u].push_back(vecinos[v]);
                    }
                    else bvec[u].push_back(vecinos[v]);
                }
            }
        }
    }

    bfs.push(1);
    bfs_vis = vector<bool>(n+1, false); bfs_vis[1] = true;
    while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            lli v = bfs.front();
            bfs.pop();

            for(auto u : grafo[v]){
                if(!bfs_vis[u]){
                    bfs_vis[u] = true;
                    bfs.push(u);

                    valb[u] = valn[v]+1; //valb es si empiezas con ese
                    valn[u] = valb[v]+2*vecinos[u]-1;
                }
            }
        }
    }

    forn(i, 1, n+1){
        sort(nvec[i].begin(), nvec[i].end());
        sort(bvec[i].begin(), bvec[i].end());
    }


    lli v, p;
    lli ans;
    lli sz;
    forn(i, 0, q){
        cin >> v >> p;
        ans = valb[v];
        //cout << ans << nl;
        if(color[v] == 1){
            sz = bvec[v].size();
            for(lli i = 0; i<sz && i<p; i++){
                ans -= 2*bvec[v][sz-i-1]-2;
            }
        }
        else{
            sz = nvec[v].size();
            for(lli i = 0; i<sz && i<p; i++){
                //cout << nvec[v][sz-i-1] << nl;
                ans -= 2*nvec[v][sz-i-1]-2;
            }
        }
        //cout << valb[v] << ' ' << valn[v] << nl;
        cout << ans << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}