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

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sizee[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

void solve(){
    int n, m; cin >> n >> m;
    int componentes = 0;
    vector<bool> on(n, false);
    vector<string> res;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u,v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi sperm(n); rep(i, 0, n) cin >> sperm[i];
    reverse(all(sperm));

    int curr;
    rep(i, 0, n){
        curr = sperm[i]-1;

        on[curr] = true;
        make_set(curr);
        componentes++;

        set<int> repres; //cuantas componentes distintas habia antes de agregarlo
        for(auto v: g[curr]){
            if(on[v]){
                repres.insert(find_set(v));
                union_sets(curr, v);
            }
        }
        componentes -= repres.size();

        if(componentes == 1){
            res.push_back("YES");
        }
        else res.push_back("NO");
    }

    reverse(all(res));
    for(auto x: res) cout << x << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}