#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vvlli grafo;
vector<lli> parent;
vector<lli> value;
lli finalmini;

lli maxmin(lli u){
    //cout << "xd";
    lli mini = 1e9+1;
    for(auto v: grafo[u]){
        if(v != parent[u]){
            mini = min(maxmin(v), mini);
        }
    }
    if(mini == 1e9+1){
        return value[u];
    }

    if(u == 0){
        return mini;
    }

    if(mini > value[u]){
        lli dif = mini-value[u];
        value[u] +=dif/2;
        mini -=dif/2;
        mini = min(mini, value[u]);
    }
    return mini;
}



void solve(){
    int N; cin >> N;
	grafo.assign(N, {});
    parent.assign(N, -1);
    value.assign(N, -1);

    forn(i, 0, N){
        cin >> value[i];
    }

	for(int i = 1; i < N; i++) {
		int u; cin >> u;
		grafo[u-1].push_back(i);
		grafo[i].push_back(u-1);
	}


	vector<bool> bfs_vis(N, false);
	queue<int> bfs; bfs.push(0); bfs_vis[0] = true;
	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();

			for(int v : grafo[u]){
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
                    parent[v] = u;
				}
            }
		}
	}

    lli minion = maxmin(0);
    cout << value[0]+minion << nl;
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}