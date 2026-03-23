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

vector<ll> parent, rnk;

void make_set(ll v) {
    parent[v] = v;
    rnk[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}


void solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> coords; 
    rep(i, 0, n){
        ll x,y; cin >> x >> y;
        coords.push_back({x,y});
    }

    vector<ll> c(n); rep(i, 0, n) cin >> c[i];
    vector<ll> k(n); rep(i, 0, n) cin >> k[i];

    vector<vector<ll>> grafo(n+1, vector<ll>(n+1, 1e18));
    rep(i, 0, n){
        rep(j, i+1, n){
            grafo[i][j] = (k[i]+k[j])*(abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second));
            grafo[j][i] = grafo[i][j];
        }
    }
    rep(i, 0, n){
        grafo[i][n] = grafo[n][i] = c[i];
    }

    

    vector<vector<ll>> edges;
    rep(i, 0, n+1){
        rep(j, i+1, n+1){
            edges.push_back({grafo[i][j], i, j});
        }
    }

    parent.resize(n+1);
    rnk.resize(n+1);
    for (int i = 0; i < n+1; i++)
    make_set(i);
    
    sort(edges.begin(), edges.end());
    ll sz = edges.size();
    ll cost = 0;
    vector<ll> stations;
    vector<pair<ll, ll>> tree;
    
    for (auto e : edges) {
        if (find_set(e[1]) != find_set(e[2])) {
            cost += e[0];
            if(e[1] == n || e[2] == n){
                stations.push_back(e[1]+e[2]-n+1);
            }
            else{
                tree.push_back({e[1]+1, e[2]+1});
            }
            union_sets(e[1], e[2]);
        }
    }
    cout << cost << endl;
    cout << stations.size() << endl;
    for(auto st : stations) cout<< st << ' ';
    cout << endl;

    cout << tree.size() << endl;
    for(auto ed : tree){
        cout << ed.first << ' ' << ed.second << endl;
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}