//https://cses.fi/problemset/task/1667/
#include <iostream> //bfs para encontrar minimo camino entre dos vertices
#include <vector>
#include <queue>
#include <utility>
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grafo(n);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        grafo[u-1].push_back(v-1);
        grafo[v-1].push_back(u-1);
 
    }
 
    vector<bool> vis(n, false);
    vector<int> path(n, -1);
    vector<int> dis(n);
    vector<int> ancestro(n);
    dis[0] = 0;
    int ans=-1;
    queue<int> bfs;
    bfs.push(0);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        vis[u] = true;
        if(u == n-1){
            ans=dis[u];
        }
 
        for(int v : grafo[u]){
            if(!vis[v]){
                ancestro[v] = u;
                dis[v] = dis[u]+1;
                vis[v] = true;
                bfs.push(v);
            }
        }
    }
 
    if(ans>-1){
        path[ans] = n-1;
        for(int i=0; i<ans; i++){
            path[ans-1-i] = ancestro[path[ans-i]];
        }
    }
 
    if(ans==-1) cout << "IMPOSSIBLE" << endl;
    else{
        cout << ans+1 << endl;
        for(int i=0; i<=ans; i++){
            cout << path[i]+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}