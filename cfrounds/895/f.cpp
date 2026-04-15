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

int n;
ll ans;
vector<ll> cost;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    
}

void solve(){
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    cost = vector<ll>(n);
    rep(i, 0, n) cin >> cost[i];
    adj = vector<vector<int>>(n);
    rep(i, 0, n){
        adj[i].push_back(a[i]-1);
    }

    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    ll ans = 0;
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) dfs(v);
        if(dfs(v) == true){
            ll mini = cost[cycle_start];
            int curr = adj[cycle_start][0];
            while(curr!=cycle_start){
                mini = min(mini, cost[curr]);
                curr = adj[curr][0];
            }
            ans += mini;
        }
    }

    ll ret = 0;
    rep(i, 0, n) ret+= cost[i]*2;
    ret -= ans;

    cout << ret << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}