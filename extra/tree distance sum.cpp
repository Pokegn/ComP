#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int n; cin >> n;
    
    int u,v;
    vector<vector<int>> edg(n+1);

    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    vector<int> padre(N+1, -1);
    vector<int> subarbol(N+1, 1);
    vector<vector<int>> by_rank;

    queue<int> bfs; bfs.push(1);

    while(bfs!=empty()){
        by_rank.push_back({});
        int sz=bfs.size();
        while(sz--){
            u=bfs.front();
            bfs.pop();
            by_rank.back().push_back(u);

            for(int v : grafo[u]){
                if(vis[v]==false){
                    bfs.push(v);
                    vis[v]=true;
                }
            }
        }
    }

    for(int depth = by_rank.size() - 1; depth >= 0; depth--)
        for(int u : by_rank[depth])
            for(int v : adj[u])
                if(v != padre[u])
                    subarbol[u] += subarbol[v];

    int ans=0;
    for(int i=2; i<n; i++){
        ans+=subarbol[u]*(n-subarbol[u]);
    }

    cout << ans;
}