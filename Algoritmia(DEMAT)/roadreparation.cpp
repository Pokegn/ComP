#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int main(){

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> grafo(m);
    vector<pair<int, int>> min_edge(n+1);
    long long int edge_cost;
    vector<int> used(n+1);

    for(int i=0; i<m; i++){
        int u, v; long long int c; cin >> u >> v >> c;
        grafo[u].push_back(make_pair(v, c));
        grafo[v].push_back(make_pair(u, c));

    }

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto [u, w]: grafo[1]){
        pq.push({w, u});
        min_edge[u] = {1, w};
    }
    min_edge[1] = {1, -1};
    used[1] = true;
    long long total_cost = 0;
    for(int i=1; i<n; i++){
        int u=-1; edge_cost=0;
        while(!pq.empty()){
            auto[w, v] = pq.top();
            pq.pop();
            if(w!= min_edge[v].second || used[v]) continue;
            u = v;
            edge_cost = w;
            break;
        }
        if(u == -1) break;

        used[u] == true;
        total_cost += edge_cost;
        
        for(auto [v, w] : grafo[u]){
            if(w < min_edge[v].second && !used[v]){
                min_edge[v] = {u, w};
                pq.push({w, v});
            }
        }
    }
    bool ans = 1;
    for(int i=1; i<=n; i++){
        
    }
}