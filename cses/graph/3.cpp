//https://cses.fi/problemset/task/1666
#include <bits/stdc++.h> //Encontrar componentes conexas y crear aristas para unir todo
using namespace std;
template <typename T, int D>
struct Vector : public vector<Vector<T, D - 1>> {
    static_assert(D > 0);
    template<typename... Args>
    Vector(int sz = 0, Args... args) : vector<Vector<T, D - 1>>(sz, Vector<T, D - 1>(args...)) {}
};
template <typename T>
struct Vector<T, 1> : public vector<T> {
    Vector(int sz = 0, const T& val = T()) : vector<T>(sz, val) {}
};

template <typename T>
struct Matrix : public vector<vector<T>> {
    Matrix(int hei = 0, int wid = 0, const T& val = T()) : vector<vector<T>>(hei, vector<T>(wid, val)) {}
};
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}


void solve(){
    int n,m; cin >> n >> m;
    vvi grafo(n+1);
    vector<pair<int, int>> anss(0);
    int i1=-1;
    int i2=-1;
    int ans=0;

    int u, v;
    forn(i, 0, m){
        cin >> u >> v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }

    vector<bool> bfs_vis(n+1, false);
    queue<int> bfs;
    forn(i, 1, n+1){
        if(bfs_vis[i] == false){
            if(i2 == -1){
                i2 = i;
            }
            else{
                ans++;
                i1 = i2;
                i2 = i;
                anss.pb({i1, i2});
            }
            bfs.push(i); bfs_vis[i] = true;

            while(!bfs.empty()){
                int bfssz = bfs.size();
                while(bfssz--){
                    int u = bfs.front();
                    bfs.pop();
                    for(int v : grafo[u]){
                        if(bfs_vis[v] == false){
                            bfs.push(v);
                            bfs_vis[v] = true;
                        }
                    }
                }
            }

        }
    }
    cout << ans << '\n';
    forn(i,0,ans){
        cout<< anss[i].first << " " << anss[i].second << '\n';
    }
}
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}