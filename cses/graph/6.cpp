//https://cses.fi/problemset/task/1669
#include <bits/stdc++.h> //bfs para encontrar un ciclo
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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n, m; cin >> n >> m;
    vvi grafo(n, vi{});
    int a,b;
    forn(i, 0, m){
        cin >> a >> b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }

    int depth;
    int bfssz;
    vi camino;
    int tamano;
    int v1, v2;
    bool flag = false;
    vector<bool> bfs_vis(n, false);
    queue<int> bfs;
    vi parent(n, -1);
    forn(i, 0, n){
        depth = 0;
        if(bfs_vis[i] == true) continue;
        bfs_vis[i] = true;
        bfs.push(i);

        while(!bfs.empty()){

            bfssz = bfs.size();

            while(bfssz--){

                int v = bfs.front();
                bfs.pop();

                for(auto u: grafo[v]){

                    if(bfs_vis[u]){
                        if(parent[v] == u) continue;
                        flag = true;
                        v1 = u;
                        v2 = v;
                        vector<bool> vis(n, 0);

                        while(v2!=-1){
                            vis[v2] = 1;
                            v2 = parent[v2];
                            //cout << 1;
                        }

                        while(vis[v1]== 0){
                            camino.push_back(v1);
                            v1 = parent[v1];
                        }

                        camino.push_back(v1);
                        int com = v1;
                        v1 = u;
                        v2 = v;
                        int temp = camino.size();

                        tamano = 1;
                        while(v2!=com){
                            tamano++;
                            v2 = parent[v2];
                        }
                        tamano+=temp;
                        cout << tamano << '\n';

                        v1 = u;
                        v2 = v;
                        cout << u+1 << ' ';
                        while(v2!=com){
                            cout << v2+1 << ' ';
                            v2 = parent[v2];
                        }
                        rof(j, temp-1, 0){
                            cout << camino[j]+1 << ' ';
                        }
                        cout << '\n';
                        return;                          
                    }
                    parent[u] = v;
                    bfs.push(u);
                    bfs_vis[u] = true;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}