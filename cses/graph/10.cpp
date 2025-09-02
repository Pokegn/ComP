#include <bits/stdc++.h>
using namespace std; //bellman-ford para encontrar las distancias de un vertice a todos con distancias negativas en O(mn),
        //y luego si hay ciclo negativo revisa si algun vertice en algun ciclo es parte de un camino al vertice n.
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
    lli n, m; cin >> n >> m;
    vector<vector<lli>> grafo(n, vector<lli>(3));
    vector<vector<lli>> grafo1(n);
    lli a, b, c;
    forn(i, 0, m){
        cin >> a >> b >> c;
        grafo.push_back({a-1, -c, b-1});
        grafo1[a-1].push_back(b-1);
    }

    vector<bool> reachn(n, false); reachn[n-1] = true;
    vector<bool> bfs_vis(n, false);
	queue<int> bfs; bfs.push(0); 
    for(int i=0; i<n-1; i++){
        bfs_vis = vector<bool>(n, false); bfs_vis[i] = true; bfs.push(i);
        while(!bfs.empty()) {
            int bfssz = bfs.size();
            while(bfssz--) {
                int u = bfs.front();
                bfs.pop();

                for(int v : grafo1[u])
                    if(!bfs_vis[v]) {
                        bfs.push(v);
                        bfs_vis[v] = true;
                    }
            }
        }
        if(bfs_vis[n-1]) reachn[i] = true;
    }

    vector<lli> ans(n, 1e16); ans[0] = 0;

    lli x;
    forn(i, 0, n-1){
        x = -1;
        for(auto v: grafo){
            if(ans[v[0]] < 1e16){
                if(ans[v[2]] > ans[v[0]] + v[1]){
                    ans[v[2]] = ans[v[0]]+v[1];
                    x = v[2];
                }
            }
        }
    }

    if(x == -1){
        cout << -ans[n-1] << nl;
    }
    else{
        forn(i, 0, n){
            x = -1;
            for(auto v: grafo){
                if(ans[v[0]] < 1e16){
                    if(ans[v[2]] > ans[v[0]] + v[1]){
                        ans[v[2]] = ans[v[0]]+v[1];
                        x = v[2];
                        if(reachn[x]){
                            cout << -1 << nl;
                            return;
                        }
                    }
                }
            }
        }
        cout << -ans[n-1] << nl;
    }

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}