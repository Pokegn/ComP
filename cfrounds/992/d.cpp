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
    lli n; cin >> n;
    lli num = 2*n;
    vvlli grafo(n+1);
    forn(i, 0, n-1){
        lli u,v; cin >> u >> v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }

    queue<lli> bfs;
    vector<bool> bfs_vis(n+1, false);
    vlli a(n+1);
    bfs.push(1); bfs_vis[1] = true; a[1] = num;

    while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            lli u = bfs.front();
            bfs.pop();


            for(auto v: grafo[u]){
                if(!bfs_vis[v]){
                    num--;
                    bfs_vis[v] = true;
                    bfs.push(v);
                    a[v] = num;
                    if((a[v]%2 != a[u]%2) && a[v]!=a[u]-1) a[v]--;
                    if(a[v] == a[u]-2) a[v]-=2;
                    num = a[v];
                }
            }
        }
    }

    forn(i, 1, n+1) cout << a[i] << ' ';
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}