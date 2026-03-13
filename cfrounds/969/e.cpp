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

vector<int> maxitree;
vector<bool> dfs_vis;

void dfs(int u, vector<vector<int>> &grafo){
    if(dfs_vis[u]) return;      
    dfs_vis[u] = true;
    maxitree[u] = u;
    for(auto v: grafo[u]){
        if(v<u) continue;
        dfs(v, grafo);
        maxitree[u] = max(maxitree[v], maxitree[u]);
    }
}

void solve(){
    int n; cin >> n;
    ll w; cin >> w;
    vector<int> p(n, -1);
    rep(i, 1, n) cin >> p[i];
    rep(i, 1, n) p[i]--;

    vector<vector<int>> grafo(n);
    rep(i, 1, n){
        grafo[i].push_back(p[i]);
        grafo[p[i]].push_back(i);
    }
    rep(i, 0, n){
        sort(all(grafo[i]));
    }

    maxitree = vector<int> (n);
    dfs_vis = vector<bool> (n, false);
    vector<vector<int>> encamino (n);  //la madre esta de i-1 a i, en que caminos desde i esta
    dfs(0, grafo);
    rep(i, 1, n){
        encamino[i] = {i-1, maxitree[i]};
    }

    vector<int> tamano(n, 0); //tamano de i a i+1
    vector<vector<int>> camino(n);
    rep(i, 1, n){
        //cout << i << endl;
        for(auto j: encamino[i]){ //i esta en el camino de j a j+1
            tamano[j]++;
            camino[j].push_back(i);
            //cout << j << ' ';
        }
        //cout << endl;
    }
    //cout << "CAMINO \n";

    // rep(i, 0, n){
    //     cout << i << endl;
    //     for(auto j: camino[i]){ //i esta en el camino de j a j+1
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = n*w;
    int llenados = 0;
    vector<int> t(n);
    vector<bool> lleno(n, false);
    ll sumadef = 0;
    rep(q, 0, n-1){
        int x; cin >> x;
        ll y; cin >> y;
        x-=1;
        t[x] = y; 
   
        // cout << "t[" << x << "] es " << y << endl;
        // cout << x << " tiene en su camino a ";
        for(auto j: encamino[x]){
            //cout << j << ' ';
            tamano[j]--;
            if(tamano[j] == 0){
                lleno[j] = true;
                llenados++;
                ll sumar = 0;
                for(auto xd: camino[j]){ //en el camino de j a j+1 esta la que acaba en xd
                    sumar += t[xd];
                }
                ans-=w - sumadef + sumar - y;
                ans+= sumar;    
                //cout << "se lleno el " << j << " y  suma es " << sumar << endl;            
            }
        } // le quito x a todos los no llenados que no tienen a x
        ans -= y*(n-llenados);
        //cout << ans << ' ';
        //le quite todos los no llenados, le agrego los no llenados que tienen a x
        for(auto j: encamino[x]) if(!lleno[j]) ans += y;
        sumadef += y;
        cout << ans << ' ';
        
    }
    cout << endl;


   
    //todos estan en exactamente 2 caminos, por tanto no estan en n-2
    //o sea que al principio la respuesta es 2nw, y cuando agrego una arista con peso x todos los caminos no llenados decrecen en x
    //y cuando agrego una que completa un camino se fija
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}