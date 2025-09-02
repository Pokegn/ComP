#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

vector<vector<int>> grafo;
vector<bool> vis;
vector<int> dis;
vector<int> ancestro;
int mi;

void dfs(int u){
    vis[u] = 1;
    for(int v : grafo[u]){
        if(!vis[v]){
            dis[v] = dis[u]+1;
            ancestro[v]=u;
            dfs(v);
        }
        else{
            if(v!=ancestro[u]){
                mi = min(abs(dis[u]-dis[v])+1, mi);
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    grafo.assign(n, {});
    vis.assign(n, 0);
    dis.assign(n, 0);
    ancestro.assign(n, 0);
    ancestro[0] = -1;
    mi=100000;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        grafo[u-1].push_back(v-1);
        grafo[v-1].push_back(u-1);

    }

    dfs(0);
    if(mi == 100000){
        cout << -1 << endl;
    }
    else{
        cout << mi << endl;
    }
    
    return 0;
}