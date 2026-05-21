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

const int MAXN =1e6+1;
int parent[MAXN];
int sizee[MAXN];

int find_set(int v){
    if(v == parent[v]){
        return parent[v];
    }
    return parent[v] = find_set(parent[v]);
}

void make_set(int v){
    parent[v] = v;
    sizee[v] = 1;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a,b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vi sperm(n); rep(i, 0, n){
        cin >> sperm[i]; sperm[i]--;
    }
    vector<pair<int, pii>> edges;
    rep(i, 0, m){
        int u,v,w; cin>> u >> v >> w; u--; v--;
        edges.push_back({w, {u,v}});
    }
    sort(all(edges), greater<pair<int, pii>>());

    int l = 0, r = m;
    while(l < r){ //binary search para encontrar la respuesta
        int m = (l+r)/2; //puedo lograrlo con los primeros m wormholes?
        rep(i, 0, n) make_set(i); //reinicio todo
        rep(i, 0, m){
            union_sets(edges[i].se.fi, edges[i].se.se);
        }
        bool cando = true;
        rep(i, 0, n){
            if(find_set(i) != find_set(sperm[i])) cando = false;
        }

        if(cando) r = m;
        else l = m+1;
    }

    if(l == 0) cout << -1 << endl;
    else
    cout << edges[l-1].fi << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}