#include <bits/stdc++.h>
using namespace std;
template <typename T, int D>
struct Vector : public vector<Vector<T, D - 1>> {
    static_assert(D > 0);
    template<typename... Args>
    Vector(int sz = 0, Args... args) : vector<Vector<T, D - 1>>(sz, Vector<T, D - 1>(args...)) {}
};
template <typename T>
struct Vector<T, 1> : public vector<T> {
    Vector(int sz = 0, const T& val = T()) : vector<T>(sz, val) {}
};

template <typename T>
struct Matrix : public vector<vector<T>> {
    Matrix(int hei = 0, int wid = 0, const T& val = T()) : vector<vector<T>>(hei, vector<T>(wid, val)) {}
};
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

const lli INF = 1e18;
vector<vector<pair<lli, lli>>> grafo;
vlli dist;
vlli s;

void dij(int o){
    int n = grafo.size();
    dist.assign(n*1001, INF);
    dist[o+n*s[o]] = 0;
    vector<bool> vis(n*1001, false);
    lli v;
    
    priority_queue<pair<lli, lli>> pq;
    pq.push({0,o+n*s[o]});

    while(!pq.empty()){
        v = pq.top().second;
        pq.pop();
        int orig = v%n;

        vis[v] = true;
        for(pair<lli, lli> u: grafo[orig]){
            lli to = u.first;
            lli dis = u.second;
            lli speed = v/n;

            lli destino = to + n*(min(speed, s[to]));
            if(dist[v]+ dis*speed < dist[destino]){
                dist[destino] = dist[v] + dis*speed;
                pq.push({-dist[destino], destino});
            }
        }
    }
}



void solve(){
    lli n; cin >> n;
    lli m; cin >> m;
    grafo.assign(n, {});
    lli u, v, w;
    forn(i, 0, m){
        cin >> u >> v >> w;
        grafo[u-1].push_back({v-1,w});
        grafo[v-1].push_back({u-1,w});
    }
    s.assign(n, 0);
    forn(i, 0, n) cin >> s[i];
    dij(0);
    lli ans=INF;
    forn(i, 1, 1001){
        ans = min(ans, dist[(n-1)+n*i]);
    }
    cout << ans << nl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}