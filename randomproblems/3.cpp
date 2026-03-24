#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

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

void solve(){
    int n, m; cin >> n >> m;
    int ready = 0;
    int extra = 0;
    vector<bool> fila(n, false);
    vector<bool> col(n, false);

    grafo = vector<vector<int>> (m+n); //el vertice i con el vertice n+x
    dfs_vis = vector<bool>(m+n, false);

    rep(i, 0, m){
        int x,y; cin >> x >> y;
        fila[x-1] = true;
        col[y-1] = true;
        if(x == y) ready++;
        grafo[m+x-1].push_back(i); //adonde va coord y
        grafo[i].push_back(m+x-1);
        grafo[m+y-1].push_back(i); //donde estoy coord y
        grafo[i].push_back(m+y-1); 
    }

    int componentes = 0;
    rep(i, 0, m){
        if(!dfs_vis[i]) componentes++;
        dfs(i);
    }

    int unos = 0;
    // cout << "unos: " << endl;
    rep(i, m, n+m){
    //     cout << i-m << ' ' << grafo[i].size() << endl;
        if(grafo[i].size() == 1){ unos++;}
    }
    // cout << endl;
    
    if(ready == m){
        cout << 0 << endl;
        return;
    }

    //cada componente crea
    //dos unos si es una fila
    //cero unos si es un ciclo
    //un uno si ya esta en posicion
    
    int ciclos = (componentes-ready-(unos/2));
    // cout << "comp " << ' ' << componentes << endl;
    // cout << "unos " << unos << endl;

    int ans = m - ready + ciclos;
    // cout << m << ' ' << ready << ' ' << ciclos << endl;
    cout << ans << endl;
    return;


    

    // bool flag = true;
    // rep(i, 0, n){
    //     if(fila[i] && (!col[i])) flag = false;
    // }
    // if(flag) extra = 1;

    cout << m-ready+extra << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}