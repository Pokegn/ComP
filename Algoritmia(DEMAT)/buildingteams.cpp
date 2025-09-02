#include <iostream>
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
    vector<int> team(n, 0);
    team[0] = 1;
    int ans=-1;
    int assigned = 0;
    bool cont=false;
    queue<int> bfs;
    int point = 0;
    while(assigned<n && cont==false){
        while(team[point]!=0 && point<n) point++;
        bfs.push(point);
        team[point] = 1;
        assigned++;
        
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            vis[u] = true;

            for(int v : grafo[u]){
                if(!vis[v]){
                    if(team[u] == 1) team[v] =2;
                    else team[v] = 1;
                    vis[v] = true;
                    bfs.push(v);
                    assigned++;
                }
                else{
                    if(team[v]==team[u]) cont=true;
                }
            }
        }
    }

        if(cont) cout <<  "IMPOSSIBLE" << endl;
        else{
            for(int i=0; i<n; i++) cout << team[i] << ' ';
            cout << endl;
        }
    return 0;
}