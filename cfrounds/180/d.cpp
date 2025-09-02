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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n; cin >> n;
    vvlli grafo(n+1, vlli(0));
    vector<pair<lli, lli>> aristas(0);

    forn(i, 0, n-1){
        lli u, v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
        aristas.push_back({u, v});
    }

    lli root = -1;
    forn(i, 1, n+1){
        if(grafo[i].size() == 2) root = i;
    }
    if(root == -1){
        cout<<"NO" << nl;
        return;
    }
    cout << "YES" << nl;
    //cout << root << nl;

    lli lson = grafo[root][0];
    lli rson = grafo[root][1];
    vector<bool> bfs_vis(n+1, false);
	queue<int> bfs; 
    bfs.push(lson); bfs_vis[lson] = true;
    bfs.push(rson); bfs_vis[rson] = true;
    bfs_vis[root] = true;

    vlli color(n+1);
    color[lson] = 1;
    color[rson] = -1;

    while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();

			for(int v : grafo[u]){
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
                    color[v] = color[u]*-1;
				}
			}
		}
	}

    for(auto x : aristas){
        if(x.first == root){
            if(color[x.second] != -1){
                cout << x.second << ' ' << x.first << nl;
            }
            else{
                cout << x.first << ' ' << x.second << nl;
            }
            continue;
        }
        if(x.second == root){
            if(color[x.first] != 1){
                cout << x.second << ' ' << x.first << nl;
            }
            else{
                cout << x.first << ' ' << x.second << nl;
            }
            continue;
        }

        if(color[x.first] == 1){
            cout << x.first << ' ' << x.second << nl;
        }
        else{
            cout << x.second << ' ' << x.first << nl;
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}