#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>> adj(N + 1);
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v),
		adj[v].push_back(u);
	}

	vector<vector<int>> sparse_table(N + 1, vector<int>(20));
	
	vector<int> depth(N + 1); int d = 1;
	vector<bool> vis(N + 1, false);
	queue<int> bfs; bfs.push(1);
	vis[1] = true, sparse_table[1][0] = 1;
	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();
			depth[u] = d;
			for(int v : adj[u])
				if(!vis[v]) {
					bfs.push(v);
					vis[v] = true;
					sparse_table[v][0] = u;
				}
		}
		d++;
	}

	for(int k = 1; k < 20; k++)
		for(int u = 1; u <= N; u++)
			sparse_table[u][k] = sparse_table[sparse_table[u][k - 1]][k - 1];

	// LCA
	int Q; cin >> Q;
	for(int i = 0; i < Q; i++) {
		int u, v, LCA; cin >> u >> v;
		if(depth[u] > depth[v])
			swap(u, v);

		// emparejar
		int diff = depth[v] - depth[u];
		for(int bit = 0; bit < 20; bit++)
			if((1 << bit) & diff)
				v = sparse_table[v][bit];

		if(u == v)
			LCA = u;

		// sacar lca
		else {
			for(int bit = 19; bit >= 0; bit--)
				if(sparse_table[u][bit] != sparse_table[v][bit])
					u = sparse_table[u][bit],
					v = sparse_table[v][bit];
			LCA = sparse_table[u][0];
		}
		cout << "LCA = " << LCA << '\n';
	}

	return 0;
}