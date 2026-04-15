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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<int> parent, rrank;

void make_set(int v) {
    parent[v] = v;
    rrank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rrank[a] < rrank[b])
            swap(a, b);
        parent[b] = a;
        if (rrank[a] == rrank[b])
            rrank[a]++;
    }
}

void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges(n);

    rep(i, 0, m){
        int u,v,w; cin >> u >> v >> w; u--; v--;
        edges.push_back({w, {u, v}});
        edges.push_back({w, {v, u}});
    }

    int cost = 0;
    vector<pair<int, pair<int, int>>> mst;
    parent.resize(n);
    rrank.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    int ans = 0;
    for (int i = 0; i<edges.size(); i++) {
        auto e = edges[i];
        vector<pair<int, pair<int, int>>> samesize;
        samesize.push_back(e);
        while(i+1 < edges.size() && (edges[i].fi == edges[i+1].fi)){
            samesize.push_back(edges[i+1]); i++;
        }

        vector<pair<int, pair<int, int>>> good;
        for(auto e : samesize){
            if(find_set(e.se.fi) != find_set(e.se.se)) good.push_back(e);
        }

        int merged = 0;
        for(auto e: good){
            if (find_set(e.se.fi) != find_set(e.se.se)) {
                merged++;
                cost += e.fi;
                mst.push_back(e);
                union_sets(e.se.fi, e.se.se);
            }
            else continue;
            //cout << e.se.fi+1 << ' ' << e.se.se+1 << endl;
        }
        ans += good.size()/2-merged;
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