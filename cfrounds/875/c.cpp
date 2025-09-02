#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        vector<vector<int>> grafo(n+1);
        vector<vector<int>> edge(n+1);
 
        int k, l;
        for(int j=0; j<n-1; j++){
            cin >> k;
            cin >> l;
 
            grafo[k].push_back(l);
            grafo[l].push_back(k);
            edge[k].push_back(l);
            edge[k].push_back(j);
            edge[l].push_back(k);
            edge[l].push_back(j);
        }
 
        int ans=1;
        vector<int> reads(n+1); reads[1]=1;
        vector<int> pos(n+1, -1); pos[1]=-1;
 
        vector<bool> visited(n+1, false);
        queue<int> bfs; bfs.push(1); visited[1]=true;
 
        while(!bfs.empty()){
            int size=bfs.size();
            for(int j=0; j<size; j++){
                int u=bfs.front();
                bfs.pop();
 
                for(int v : grafo[u]){
                    if(!visited[v]){
                        bfs.push(v);
                        visited[v]=true;
 
                        for(int x=0; x<edge[v].size()-1; x+=2){
                            if(edge[v][x]==u){
                                k=edge[v][x+1];
                            }
                        }
                        pos[v]=k;
 
                        if(k<pos[u]) reads[v]=reads[u]+1;
                        else reads[v]=reads[u];
 
                        if(ans<reads[v]) ans=reads[v];
                    }
                }
            }
        }
        cout << ans << endl;
    }
}