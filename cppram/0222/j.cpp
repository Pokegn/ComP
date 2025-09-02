#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n,w,l; cin >> n >> w >> l;
    vlli x(n), y(n), r(n);
    forn(i, 0, n){
        cin >> x[i] >> y[i] >> r[i];
    }

    vvlli grafo(n, vlli(0));

    forn(i, 0, n){
        forn(j, i+1, n){
            if(((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) <= (r[i]+r[j])*(r[i]+r[j])){
                grafo[i].pb(j);
                grafo[j].pb(i);
            }
        }
    }

    lli ans = 0;
    bool tocaleft, tocaright;

    vector<bool> bfs_vis(n, false);
    queue<int> bfs; 
    forn(i, 0, n){
        tocaleft = false;
        tocaright = false;
        if(bfs_vis[i]) continue;
        //cout << "XD";
        bfs = queue<int>();
        bfs.push(i); bfs_vis[i] = true;
        while(!bfs.empty()) {
            int bfssz = bfs.size();
            while(bfssz--) {
                int u = bfs.front();
                bfs.pop();
                if(x[u]-r[u]<=0) tocaleft = true;
                if(x[u]+r[u]>=w) tocaright = true;
    
                for(int v : grafo[u]){
                    if(!bfs_vis[v]) {
                        bfs.push(v);
                        bfs_vis[v] = true;
                    }
                }
            }
        }
        if(tocaleft && tocaright) ans++;
    }

    cout << ans << nl;


}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}