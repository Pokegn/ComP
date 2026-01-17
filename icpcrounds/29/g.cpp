#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<int>> grafo;

	

void solve(){
    int n; cin >> n;
    vector<int> a(n+1); for(int i=1; i<n+1; i++) cin >> a[i];
    int k; cin >> k;
    vector<vector<int>> machin(k+1, vector<int>(n+1));
    grafo.assign(n+1, {});


    for(int i=1; i<k+1; i++){
        for(int j=1;  j<=n; j++){
            int u; cin >> u;
            if(i!=u){
                grafo[u].push_back(j);
                grafo[j].push_back(u);
            }
        }
    }

    int x; cin >> x;
    int obj = -1;
    for(int i=1; i<=n; i++){
        if(a[i] == x) obj = i;
    }
    //cout <<"obj " <<  obj << endl;
	vector<bool> bfs_vis(n+1, false);
	queue<int> bfs; bfs.push(1); bfs_vis[1] = true;
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
	}

    if(bfs_vis[obj]){
        cout << "YES";
    }
    else cout << "NO";
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}