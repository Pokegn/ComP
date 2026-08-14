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
vector<int> lst[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    lst[v] = {v};
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap(a, b);

        while(!lst[b].empty()){
            int v = lst[b].back();
            parent[v] = a;
            lst[b].pop_back();
            lst[a].push_back(v);
        }
    }
}

void solve(){
    int n, m, t; cin >> n >> m >> t;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> grid(n*m);
    vector<ll> ans(n*m);
    rep(i, 0, n*m) cin >> grid[i];

    rep(i, 0, n){
        rep(j, 0, m){
            if(j<m-1) edges.push_back({abs(grid[i*m+j] - grid[i*m+j+1]), {i*m+j, i*m+j+1}});
            if(i<n-1) edges.push_back({abs(grid[i*m+j] - grid[i*m+j+m]), {i*m+j, i*m+j+m}});
        }
    }

    sort(all(edges)); //yipiiii estan sorteadas on va sortir l'auberge

    rep(i, 0, n*m) make_set(i);
    for(auto e: edges){
        //cout << e.fi << ' ' << e.se.fi/m << ' ' << e.se.fi%m << ' ' << e.se.se/m << ' ' << e.se.se%m << endl;
        int v1 = e.se.fi, v2 = e.se.se;
        if(find_set(v1) == find_set(v2)) continue;
        int len = e.fi;
        bool alrdy1 = (lst[find_set(v1)].size() >= t);
        bool alrdy2 = (lst[find_set(v2)].size() >= t);

        if(lst[find_set(v1)].size() + lst[find_set(v2)].size() >= t){
            if(!alrdy1){
                for(auto v:lst[find_set(v1)]){
                    ans[v] = len;
                } 
            }
            if(!alrdy2){
                for(auto v:lst[find_set(v2)]){
                    ans[v] = len;
                }
            }
        }
        union_sets(v1, v2);
    }

    int k;
    ll ret = 0;
    rep(i, 0, n*m){
        cin >> k;
        //cout << ans[i]<< ' ';
        if(k == 1){
            ret += ans[i];
        } 
    }
    cout << ret << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    //cin >> t;
    while(t--) solve();
    return 0;
}