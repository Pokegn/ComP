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

const int MAXN = 1000001;
int parent[MAXN];
int sizee[MAXN];

int find_set(int u){
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void make_set(int u){
    parent[u] = u;
    sizee[u] = 1;
}

void union_sets(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(sizee[u] < sizee[v]) swap(u, v);
    parent[v] = u;
    sizee[u]+=sizee[v];
}

char g[1000][1000];

int getId(int m, int n){
    return 1000*m + n;
}

void solve(){
    int n, m; cin >> n >> m;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> g[i][j];
            make_set(getId(i, j));
        }
    }


    rep(i, 0, n){
        rep(j, 0, m){
            if(g[i][j] == '.'){
                if(i-1 >= 0){
                    if(g[i-1][j] == '.') union_sets(getId(i, j), getId(i-1, j));
                }
                if(i+1 < n){
                    if(g[i+1][j] == '.') union_sets(getId(i, j), getId(i+1, j));
                }
                if(j-1 >= 0){
                    if(g[i][j-1] == '.') union_sets(getId(i, j), getId(i, j-1));
                }
                if(j+1 < m){
                    if(g[i][j+1] == '.') union_sets(getId(i, j), getId(i, j+1));
                }
            }
        }
    }

    rep(i, 0, n){
        rep(j, 0, m){
            if(g[i][j] != '.'){
                set<int> ids;
                if(i-1 >= 0){
                    if(g[i-1][j] == '.'){
                        ids.insert(find_set(getId(i-1, j)));
                    }
                }
                if(i+1 < n){
                    if(g[i+1][j] == '.'){
                        ids.insert(find_set(getId(i+1, j)));
                    }
                }
                if(j-1 >= 0){
                    if(g[i][j-1] == '.'){
                        ids.insert(find_set(getId(i, j-1)));
                    }
                }
                if(j+1 < m){
                    if(g[i][j+1] == '.'){
                        ids.insert(find_set(getId(i, j+1)));
                    }
                }
                int ans = 1;
                for(auto x: ids) ans += sizee[find_set(x)];
                ans%=10;
                g[i][j] = ('0'+ans);
            }
        }
    }

    rep(i, 0, n){
        rep(j, 0, m){
            cout << g[i][j];
        }
        cout << endl;
    }
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}