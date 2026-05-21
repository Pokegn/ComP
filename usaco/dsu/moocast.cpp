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
int sizee[MAXN];
int parent[MAXN];

void make_set(int v){
    parent[v] = v;
    sizee[v] = 1;
}

int find_set(int v){
    if(parent[v] == v){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a, b);
        parent[b] = a;
        sizee[a] +=sizee[b];
    }
}

void solve(){
    int n; cin >> n;
    vector<pii> locs(n);
    rep(i, 0, n) cin >> locs[i].first >> locs[i].second;
    vector<pair<int, pii>> edges;
    rep(i, 0, n){
        for(int j = i+1; j<n; j++){
            int dist = (locs[i].fi - locs[j].fi)*(locs[i].fi - locs[j].fi)
                + (locs[i].se - locs[j].se)*(locs[i].se - locs[j].se);
            edges.push_back({dist, {i, j}});
        }
    }

    sort(all(edges));

    rep(i, 0, n) make_set(i);
    int componentes = n;

    int ans = 0;
    int idx = 0;
    while(componentes > 1){
        ans = edges[idx].fi;
        auto curredge = edges[idx];
        int u = curredge.se.fi, v = curredge.se.se;
        if(find_set(u) != find_set(v)) componentes--;
        union_sets(u, v);
        idx++;
    }    
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}