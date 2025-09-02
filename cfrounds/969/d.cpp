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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}



vector<vector<int>> grafo;
vector<bool> dfs_vis;
vector<char> valores;
lli hojaschidas;
lli hojasuno;
lli hojascero;

void dfs(int u) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
    bool hoja = true;
	for(int v : grafo[u])
		if(!dfs_vis[v]){
			dfs(v);
            hoja = false;
        }

    if(hoja == true){
        if(valores[u] == '?'){
            hojaschidas++;
        }
        if(valores[u] == '1'){
            hojasuno++;
        }
        if(valores[u] == '0'){
            hojascero++;
        }
    }
}


void solve() {
    lli que = 0;
	int N; cin >> N;
    hojascero = 0;
    hojaschidas = 0;
    hojasuno = 0;
	grafo.assign(N+1, {});
    dfs_vis.assign(N+1, false);

	for(int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

    valores.assign(N+1, '.');

    string s; cin >> s;
    forn(i, 1, N+1){
        valores[i] = s[i-1];
    }
    forn(i, 0, N){
        if(s[i] == '?') que++;
    }

    dfs(1);

    if(valores[1] == '1'){
        cout << hojascero+(hojaschidas+1)/2 << nl;
        return;
    }

    if(valores[1] == '0'){
        cout << hojasuno + (hojaschidas+1)/2 << nl;
        return;
    }


    if(valores[1] == '?'){


        if(hojasuno == hojascero){
            if((que-1-hojaschidas)%2 == 1){
                cout << hojascero+(hojaschidas+1)/2 << nl;
                return;
            }
            else{
                cout << hojascero+hojaschidas/2 << nl;
                return;
            }
        }



        if(hojasuno > hojascero){
            hojaschidas--;
            cout << hojasuno+(hojaschidas+1)/2 << nl;
            return;
        }

        if(hojasuno < hojascero){
            hojaschidas--;
            cout << hojascero+(hojaschidas+1)/2 << nl;
            return;
        }

    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}