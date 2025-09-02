#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<bool> dfs_vis;

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
	for(int v : grafo[u])
		if(!dfs_vis[v])
			dfs(v);
}

int main() {
	int n; cin >> n;
	grafo.assign(n, {});

	int M; cin >> M;
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	vector<bool> bfs_vis(n, false);
	queue<int> bfs; bfs.push(0); bfs_vis[0] = true;
	int depth = 0;
	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();

			for(int v : grafo[u]){
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
				}
			}
		}
		depth++;
	}
}