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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli N; cin >> N;
	vvlli grafo(N+1, vlli(0));

	int M = N-1;
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

    vector<bool> es_hoja(N+1, false);
	vector<bool> bfs_vis(N+1, false);
    vlli vecinos(N+1, 0);
    vlli vecinosnojas(N+1, 0);

	queue<int> bfs; bfs.push(1); bfs_vis[1] = true;
	int depth = 0;
	while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            lli v = bfs.front();
            bfs.pop();

            for(auto u : grafo[v]){
                vecinos[v]++;
                if(!bfs_vis[u]){
                    bfs_vis[u] = true;
                    bfs.push(u);
                }
            }
        }
    }

    bfs.push(1);
    bfs_vis = vector<bool>(N+1, false); bfs_vis[1] = true;
    while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            lli v = bfs.front();
            bfs.pop();

            for(auto u : grafo[v]){
                if(vecinos[u]>1) vecinosnojas[v]++;
                if(!bfs_vis[u]){
                    bfs_vis[u] = true;
                    bfs.push(u);
                }
            }
        }
    }

    vector<pair<lli, lli>> parejas(N);
    forn(i, 0, N) parejas[i] = {vecinos[i+1], i+1};
    sort(parejas.begin(), parejas.end(), greater<pair<lli, lli>>());

    lli ans = 1;
    lli primero = parejas[0].second;
    lli segundo = parejas[1].second;
    if(N == 2){
        cout << 0 << nl;
        return;
    }
    lli tercero = parejas[2].second;

    lli ans12, ans13, ans23;

    ans12 = vecinos[primero]+vecinos[segundo]-1;
    ans13 =vecinos[primero]+vecinos[tercero]-1;
    ans23 = vecinos[segundo]+vecinos[tercero]-1;

    for(auto u: grafo[primero]){
        if(u == segundo){
            ans12--;
            //if(vecinos[segundo] == 1) ans12--;
        }
        if(u == tercero){
            ans13--;
            //if(vecinos[tercero] == 1) ans13--;
        }
    }
    for(auto u: grafo[segundo]){
        if(u == tercero){
            ans23--;
            //if(vecinos[tercero] == 1) ans23--;
        }
    }
    ans = max({ans12, ans13, ans23});

    vlli ans1(N+1, -1);
    forn(i, 1, N+1){
        if(i == primero) continue;
        ans1[i] = vecinos[primero]+vecinos[i]-1;
    }
    for(auto u:grafo[primero]){
        ans1[u]--;
    }
    forn(i, 1, N) ans = max(ans, ans1[i]);

    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}