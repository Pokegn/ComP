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

int encode(int a, int b){
    return 1000*a + b;
}

pii decode(int d){
    return {d/1000, d%1000};
}

const int MAXN = 1e6+2;
int parent[MAXN];
int grid[1001][1001];
int ans[1001][1001];
bool processed[1001][1001];
vector<int> lst[MAXN];

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v){
    lst[v] = vector<int>(1, v);
    parent[v] = v;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(grid[decode(a).fi][decode(a).se] < grid[decode(b).fi][decode(b).se]) swap(a,b); 
        if(grid[decode(a).fi][decode(a).se] == grid[decode(b).fi][decode(b).se]){
            if (lst[a].size() < lst[b].size()) swap(a, b);
            while (!lst[b].empty()) {
                int v = lst[b].back();
                lst[b].pop_back();
                parent[v] = a;
                lst[a].push_back(v);
            }
        }
        parent[b] = a;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> grid[i][j];
    rep(i, 0, n) rep(j, 0, m) ans[i][j] = 0;
    rep(i, 0, n) rep(j, 0, m) processed[i][j] = false;

    vector<vector<pii>> h(1000001);
    rep(i, 0, n) rep(j, 0, m) h[grid[i][j]].push_back({i, j}); //los que tienen altitud h :)

    //o sea, voy a checar si el papa de mis vecinos es mayor que yo, y si si me mergeo :D

    for(int ii = 1000000; ii>=0; ii--){
        for(auto p : h[ii]){
            int i = p.fi, j = p.se;
            processed[i][j] = true;
            vector<pii> to_unite;
            make_set(encode(i, j));

            if(i>0 && grid[i-1][j] >= ii){
                if(processed[i-1][j])
                to_unite.push_back({i-1,j});
            }
            if(i<n-1 && grid[i+1][j] >= ii){
                if(processed[i+1][j])
                to_unite.push_back({i+1,j});
            }
            if(j>0 && grid[i][j-1] >= ii){
                if(processed[i][j-1])
                to_unite.push_back({i,j-1});
            }
            if(j<m-1 && grid[i][j+1] >= ii){
                if(processed[i][j+1])
                to_unite.push_back({i,j+1});
            }

            for(pii uni : to_unite){
                int repre1 = find_set(encode(uni.fi, uni.se));
                int repre2 = find_set(encode(i,j));
                if(repre1 == repre2) continue;
                int top1 = grid[decode(repre1).fi][decode(repre1).se];
                int top2 = grid[decode(repre2).fi][decode(repre2).se];

                if(top1 > top2){
                    for(auto xd: lst[repre2]){
                        ans[decode(xd).fi][decode(xd).se] = max(ii, ans[decode(xd).fi][decode(xd).se]);
                    }
                }

                if(top1 < top2){
                    for(auto xd: lst[repre1]){
                        ans[decode(xd).fi][decode(xd).se] = max(ii, ans[decode(xd).fi][decode(xd).se]);
                    }
                }
                union_sets(repre1, repre2);
            }
        }
    }
    
    rep(i, 0, n){
        rep(j, 0, m) cout << grid[i][j] - ans[i][j] <<' ';
        cout << endl;
    }
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}