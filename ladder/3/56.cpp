#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo;
vector<bool> dfs_vis;

void dfs(int u){
    if(dfs_vis[u]) return;
    
    dfs_vis[u]=true;

    for(int v:grafo[u]){
        if(!dfs_vis[v]) dfs(v);
    }
}

int main(){
    int n; cin >> n;
    int x,y;
    grafo.assign(n+2001, {});
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        grafo[x+n].push_back(i);
        grafo[y+1000+n].push_back(i);
        grafo[i].push_back(x+n);
        grafo[i].push_back(y+1000+n);
    }
    int ans=0;

    dfs_vis.assign(n+2001, false);
    for(int u=1; u<=n; u++){
        if(!dfs_vis[u]){
            ans++;
            dfs(u);
        }
    }

    cout << ans-1;

} 

//checo cada columna y marco a los que esten marcados de ahi
//fin