#include <bits/stdc++.h>
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
    int N, M, x0, y0; cin >> N >> M >> x0 >> y0;
    vvi tabla(N, vi(M));
    vvi grafo(N*M, vi{});
    //cout << "xd";
    forn(i, 0, N){
        forn(j, 0, M){
            cin >> tabla[i][j];
        }
    }
    //cout << "xd";
    vi salidas(0);

    forn(i, 0, N){
        forn(j, 0, M){
            if(tabla[i][j] % 2 == 0){ //izq
                if(j!=0) grafo[i*M+j].push_back(i*M+j-1);
                if(j==0) salidas.push_back(i*M+j);
            }
            tabla[i][j]/=2;


            if(tabla[i][j] % 2 == 0){ //arriba
                if(i!=0) grafo[i*M+j].push_back(i*M+j-M);
                else salidas.push_back(i*M+j);
            }
            tabla[i][j]/=2;


            if(tabla[i][j] % 2 == 0){ //der
                if(j!=M-1) grafo[i*M+j].push_back(i*M+j+1);
                else salidas.push_back(i*M+j);
            }
            tabla[i][j]/=2;


            if(tabla[i][j] % 2 == 0){ //abajo
                if(i != N-1) grafo[i*M+j].push_back(i*M+j+M);
                else salidas.push_back(i*M+j);
            }
        }
    }



    if(salidas.size() == 0){
        cout << -1 << nl;
        return;
    }

    int xd = salidas.size();
    vector<bool> bfs_vis(N*M, false);
	queue<int> bfs; bfs.push(M*x0+y0-M-1); bfs_vis[M*x0+y0-M-1] = true;
	int depth = 0;
	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
            forn(i, 0, xd){
                if(u == salidas[i]){
                    cout << depth << nl;
                    return;
                }
            }
			bfs.pop();

			for(int v : grafo[u])
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
				}
		}
		depth++;
	}

    cout << -1 << nl;
    return;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}