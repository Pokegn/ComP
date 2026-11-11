#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<int>> g;
vector<bool> dfs_vis;
vi color;

int a, b;

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
	for(int v : g[u]){
		if(!dfs_vis[v]){
			dfs(v);
            color[v] = 2-color[u];
            if(color[v] == 1) a++;
            else b++;
        }
    }
}

void solve(){
    int n; cin >> n;
    g = vector<vector<int>> (2*n, vi(0));
    dfs_vis = vector<bool>(2*n, false);
    color = vi(2*n, -1);
    vector<bool> isfrog(2*n, false);

    int frogs = 0;

    // return;
    string s1; cin >> s1;
    string s2; cin >> s2;

    rep(i, 0, n){
        if(s1[i] == 'f') frogs++;
        if(s2[i] == 'f') frogs++;
    }

    if(frogs%2 == 1) cout << 1<< endl;
    else cout << 0 << endl;
    return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}