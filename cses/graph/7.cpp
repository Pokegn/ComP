//https://cses.fi/problemset/task/1195
#include <bits/stdc++.h> //multiples bfs para encontrar una salida en una cuadricula 
                         //mientras hay casillas que quieren bloquear el paso
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

int n,m;
vector<char> a;

bool muerto(int x){
    if(a[x] == 'M' || a[x] == '#' || a[x] == 'A') return 1;
    return 0;
}

int up(int x){
    if(x-m < 0) return -1;
    return x-m;
}
int down(int x){
    if(x+m >= n*m) return -1;
    return x+m;
}
int left(int x){
    if(x%m == 0) return -1;
    return x-1;
}
int right(int x){
    if(x%m == m-1) return -1;
    return x+1;
}
bool isborder(int x){
    if(right(x) == -1 || left(x) == -1 || up(x) == -1 || down(x) == -1) return 1;
    return 0;
}

void solve(){
    cin >> n >> m;
    a.assign(n*m, 'x');
    vector<int> parent(n*m, -1);
    queue<int> monsters;
    queue<int> yo;
    int pos;
    vector<bool> avis(n*m, 0);
    vector<char> ans;

    forn(i, 0, n*m){
        cin >> a[i];
        if(a[i] == 'M') monsters.push(i);
        if(a[i] == 'A'){
            yo.push(i);
            pos = i;
        }
    }

    if(isborder(pos)){
        cout << "YES" << nl << 0;
        return;
    }

    avis[pos] = true;
	int depth = 0;
	while(!yo.empty()) {

        int bfsszmon = monsters.size();
		while(bfsszmon--) {
			int u = monsters.front();
			monsters.pop();
            vi grafom = {};
            if(up(u) != -1 && !muerto(up(u))) grafom.push_back(up(u));
            if(down(u) != -1 && !muerto(down(u))) grafom.push_back(down(u));
            if(left(u) != -1 && !muerto(left(u))) grafom.push_back(left(u));
            if(right(u) != -1 && !muerto(right(u))) grafom.push_back(right(u));

			for(int v : grafom){
				monsters.push(v);
                a[v] = '#';
            }

		}

		int bfsszyo = yo.size();
		while(bfsszyo--) {
			int u = yo.front();
			yo.pop();

            vi grafo = {};
            if(up(u) != -1 && !muerto(up(u))) grafo.push_back(up(u));
            if(down(u) != -1 && !muerto(down(u))) grafo.push_back(down(u));
            if(left(u) != -1 && !muerto(left(u))) grafo.push_back(left(u));
            if(right(u) != -1 && !muerto(right(u))) grafo.push_back(right(u));

			for(int v : grafo){
				if(!avis[v]) {
                    parent[v] = u;
					yo.push(v);
					avis[v] = true;

                    if(isborder(v)){ //si ya ganamos
                        cout << "YES" << nl;
                        
                        while(v!=pos){
                            //cout << v << ' ';
                            if(left(v) == parent[v]){
                                ans.push_back('R');
                            }
                            if(right(v) == parent[v]){
                                ans.push_back('L');
                            }
                            if(down(v) == parent[v]){
                                ans.push_back('U');
                            }
                            if(up(v) == parent[v]){
                                ans.push_back('D');
                            }
                            v = parent[v];
                        }

                        int sz = ans.size();
                        cout << sz << nl;
                        rof(j, sz-1, 0) cout << ans[j];
                        cout << nl;
                        return;
                    }

				}
            }
		}
		depth++;

	}
    std::cout << "NO" << '\n';
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}