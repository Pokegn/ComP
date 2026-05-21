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
int n;

int encode(int i, int j){
    return n*i + j;
}

void make_set(int v){
    parent[v] = v;
    sizee[v] = 1;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a), b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a,b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

void solve(){
    cin >> n;
    vector<vi> grid(n, vi(n));
    rep(i,0,n) rep(j,0,n) cin >> grid[i][j];
    
    int l = 0, r = 1000000;
    int maxsz;
    while(l < r){
        maxsz = 1;
        rep(i, 0, n) rep(j, 0, n) make_set(encode(i, j));
        int m = (l+r)/2;
        rep(i, 0, n) rep(j, 0, n){
            if(i+1 < n && abs(grid[i][j] - grid[i+1][j]) <= m){
                union_sets(encode(i,j), encode(i+1,j));
            }
            if(j+1 < n && abs(grid[i][j] - grid[i][j+1]) <= m){
                union_sets(encode(i,j), encode(i, j+1));
            }
            maxsz = max(maxsz, sizee[find_set(encode(i,j))]);
        }

        if(maxsz >= (n*n+1)/2) r = m;
        else l = m+1;
    }
    cout << l << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}