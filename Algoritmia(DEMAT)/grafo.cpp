#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(10000);

int main(){
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}