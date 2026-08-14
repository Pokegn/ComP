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

typedef vector<bitset<200>> vb;
struct Maxclique {
double limit=0.025, pk=0;
struct Vertex { int i, d=0; };
typedef vector<Vertex> vv;
vb e;
vv V;
vector<vi> C;
vi qmax, q, S, old;
void init(vv& r) {
for (auto& v : r) v.d = 0;
for (auto& v : r) for (auto j : r) v.d += e[v.i][j.i];
sort(all(r), [](auto a, auto b) { return a.d > b.d; });
int mxD = r[0].d;
rep(i,0,sz(r)) r[i].d = min(i, mxD) + 1;
}
void expand(vv& R, int lev = 1) {
S[lev] += S[lev - 1] - old[lev];
old[lev] = S[lev - 1];
while (sz(R)) {
if (sz(q) + R.back().d <= sz(qmax)) return;
q.push_back(R.back().i);
vv T;
for(auto v:R) if (e[R.back().i][v.i]) T.push_back({v.i});
if (sz(T)) {
if (S[lev]++ / ++pk < limit) init(T);
int j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);
C[1].clear(), C[2].clear();
for (auto v : T) {
int k = 1;
auto f = [&](int i) { return e[v.i][i]; };
while (any_of(all(C[k]), f)) k++;
if (k > mxk) mxk = k, C[mxk + 1].clear();
if (k < mnk) T[j++].i = v.i;
C[k].push_back(v.i);
}
if (j > 0) T[j - 1].d = 0;
rep(k,mnk,mxk + 1) for (int i : C[k])
T[j].i = i, T[j++].d = k;
expand(T, lev + 1);
} else if (sz(q) > sz(qmax)) qmax = q;
q.pop_back(), R.pop_back();
}
}
vi maxClique() { init(V), expand(V); return qmax; }
Maxclique(vb conn) : e(conn), C(sz(e)+1), S(sz(C)), old(S) {
rep(i,0,sz(e)) V.push_back({i});
}
};


void solve(){
    int n, m; cin >> n >> m;
    vector<string> qs(n, "");
    vector<int> queries(n);
    rep(i, 0, n){
        cin >> queries[i];
        if(queries[i] == 2) cin >> qs[i];        
    }

    set<string> ppl;
    rep(i, 0, n) if(qs[i] != "") ppl.insert(qs[i]);
    map<string, int> id;
    int currid = 0;
    for(auto s: ppl){
        id[s] = currid;
        currid++;
    }

    int dp[n][m];
    vb grafo(200);
    set<int> weones;
    rep(i, 0, n){
        if(queries[i] == 1){
            for(auto x: weones){
                for(auto y: weones){
                    if(x == y) continue;
                    grafo[x][y] = 1;
                    grafo[y][x] = 1;
                }
            }
            weones.clear();
        }
        if(queries[i] == 2){
            weones.insert(id[qs[i]]);
        }
    }
    for(auto x: weones){
        for(auto y: weones){
            if(x == y) continue;
            grafo[x][y] = 1;
            grafo[y][x] = 1;
        }
    }
    weones.clear();

    rep(i, 0, m){
        rep(j, 0, m){
            if(i == j) continue;
            grafo[i][j] = 1-grafo[i][j];
        }
    }

    Maxclique pito(grafo);
    cout << pito.maxClique().size() << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}