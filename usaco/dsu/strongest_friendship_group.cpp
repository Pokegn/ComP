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

const int MAXN = 1e6+1;
int parent[MAXN];
int sizee[MAXN];
vector<set<pair<int, int>>> lst(MAXN);

int find_set(int u){
    if(u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

void make_set(int u){
    lst[u].insert({0,u});
    parent[u] = u;
    sizee[u] = 1;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b); 
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a,b);
        sizee[a] += sizee[b];
        parent[b] = a;
        while (!lst[b].empty()) {
            pair<int, int> v = *lst[b].begin();
            lst[b].erase(v);
            parent[v.second] = a;
            lst[a].insert(v); //afuera tengo que manejar la actualizacion de las aristas
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u,v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<set<int>> withdeg(n);
    vector<int> grado(n);
    rep(i, 0, n) grado[i] = (int)(g[i].size());
    rep(i, 0, n) withdeg[grado[i]].insert(i);

    vector<int> removeOrder;
    rep(currdeg, 0, n){
        while(!withdeg[currdeg].empty()){ //si quito uno le bajo el lugar a sus vecinos, excepto de si bajaria de currdeg
            auto curr = *withdeg[currdeg].begin();
            for(auto v: g[curr]){ //para cada vecino...
                if(grado[v]!=-1){ //si no lo he quitado...
                    withdeg[grado[v]].erase(v);
                    if(grado[v] > currdeg) grado[v]--;
                    withdeg[grado[v]].insert(v); //le bajo uno de prioridad
                }
            }
            removeOrder.push_back(curr);
            grado[curr] = -1;
            withdeg[currdeg].erase(curr);
        }
    }

    //for(auto x: removeOrder) cout << x << ' ';

    reverse(all(removeOrder));

    ll ans = 0;

    rep(i, 0, n) grado[i] = 0;
    rep(i, 0, n) parent[i] = -1;

    int cuantas;
    for(auto i: removeOrder){
        make_set(i);
        //cuantas = 0;
        for(auto v: g[i]){
            if(parent[v] == -1) continue;
            //cuantas++;
            //si ya lo puse, toca mergear
            lst[find_set(i)].erase({grado[i], i}); //actualizo el set de grados por la arista 
            grado[i]++;
            lst[find_set(i)].insert({grado[i], i});

            lst[find_set(v)].erase({grado[v], v});
            grado[v]++;
            lst[find_set(v)].insert({grado[v], v});
            union_sets(i, v);

        }
        //cout << i << ' ' << sizee[find_set(i)] << ' ' << (*lst[find_set(i)].begin()).fi << ' ' << cuantas <<  endl;
        ans = max(ans, (ll)sizee[find_set(i)] * ((*lst[find_set(i)].begin()).fi));
    }

    cout << ans << endl;
    return;    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}