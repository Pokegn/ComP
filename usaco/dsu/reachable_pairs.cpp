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

const int MAXVAL = 1e6+1;
int parent[MAXVAL];
ll sizee[MAXVAL];
vector<vector<int>> pendingMerges(MAXVAL, vector<int>(0));
ll ans = 0;

ll combs(ll x){
    if(x <= 1) return 0;
    return (x*(x-1))/2;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v){
    parent[v] = v;
    sizee[v] = 0ll;
}

void union_meco(int a, int b){ //union w/o altering size
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        swap(a, b);
        parent[b] = a;
    }
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a,b);
        ans -= combs(sizee[a]); ans-= combs(sizee[b]);
        sizee[a]+= sizee[b];
        ans += combs(sizee[a]);
        parent[b] = a;
    }
}

void solve(){
    int n,m; cin >> n >> m;
    string str; cin >> str;
    vector<int> s(n);
    rep(i, 0, n) s[i] = (int)(str[i] -'0');
    
    vector<vi> g(n);
    vector<pii> edges;
    rep(i, 0, m){
        int u,v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }
    
    rep(i, 0, n) make_set(i);

    vector<vector<int>> toAdd(n);
    for(auto p: edges){
        int i = p.fi, j = p.se;
        if(s[i] == 1 && s[j] == 1) union_meco(i, j);
        else{
            if(s[i] == 1){
                toAdd[j].push_back(i);
                continue;
            }
            if(s[j] == 1){
                toAdd[i].push_back(j);
                continue;
            }
            toAdd[min(i,j)].push_back(max(i,j));
        }
    }

    vector<ll> respuestas(n);
    for(int i = n-1; i>=0; i--){
        ans -= combs(sizee[find_set(i)]);
        sizee[find_set(i)]++;
        ans += combs(sizee[find_set(i)]);
        for(auto j: toAdd[i]) union_sets(i,j);
        respuestas[i] = ans;
    }

    rep(i, 0, n) cout << respuestas[i] << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}