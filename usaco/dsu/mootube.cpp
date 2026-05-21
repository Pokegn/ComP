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

int find_set(int u){
    if(parent[u] == u){
        return u;
    }
    return parent[u] = find_set(parent[u]);
}

void make_set(int u){
    parent[u] = u;
    sizee[u] = 1;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(sizee[a] < sizee[b]) swap(a,b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<int, pii>> edges;
    rep(i, 0, n-1){
        int u,v; cin >> u >> v; u--; v--;
        int w; cin >> w;
        edges.push_back({w, {u,v}});
    }
    sort(all(edges), greater<pair<int, pair<int, int>>>());
    vector<pair<int, int>> queries;

    rep(i, 0, q){
        int q1, q2; 
        cin >> q1 >> q2; q2--; queries.push_back({q1, q2});
    }
    vector<pii> sortedqueries = queries;
    sort(all(sortedqueries), greater<pii>());
    
    rep(i, 0, n) make_set(i);

    map<pair<int, int>, int> ans;
    //voy a ir tomando en cuenta las aristas en orden, de mayor a menor
    //antes de procesar la arista i, voy a checar todas las queries que
    //no haya procesado que tengan un valor mayor al peso de la arista i
    int queryidx = 0;
    pii currquery;
    int aristas = edges.size();
    rep(i, 0, aristas){
        auto curredge = edges[i];
        while(queryidx < q && sortedqueries[queryidx].fi > curredge.first){
            currquery = sortedqueries[queryidx];
            ans[currquery] = sizee[find_set(currquery.se)] - 1;
            queryidx++;
        }
        union_sets(curredge.se.fi, curredge.se.se);
    }
    while(queryidx < q){
        currquery = sortedqueries[queryidx];
        ans[currquery] = sizee[find_set(currquery.se)] - 1;
        queryidx++;
    }

    rep(i, 0, q){
        cout << ans[queries[i]] << endl;
    }
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}