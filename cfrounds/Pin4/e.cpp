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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, m; cin >> n >> m;
    vvlli grafo(n+1);
    lli u,v;
    forn(i, 0, m){
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);        
    }

    bool bipartita = true;

    vi color(n+1, 0);
    vector<bool> bfs_vis(n+1, false);
    queue<lli> bfs; 
    forn(i, 1, n+1){
        if(bfs_vis[i] == true) continue;
        //cout << "xd" << nl;
        color[i] = 1;
        bfs.push(i); bfs_vis[i] = true;

        while(!bfs.empty()) {
            int bfssz = bfs.size();
            while(bfssz--) {
                int u = bfs.front();
                bfs.pop();

                for(lli v : grafo[u]){

                    if(bfs_vis[v] && color[v] == color[u]){
                        //cout << color[u] << ' ' <<  color[v] << ' ';
                        bipartita = false;
                    } 
                    if(!bfs_vis[v]) {
                        bfs.push(v);
                        bfs_vis[v] = true;
                        color[v] = color[u]*(-1);
                        //cout << color[v] << color[u] << nl;
                    }
                }
            }
        }
    }

    vlli blanco;
    vlli negro;
    forn(i, 1, n+1){
        if(color[i] == 1) blanco.push_back(i);
        else negro.push_back(i);
    }

    lli bl = blanco.size();
    lli neg = negro.size();
    lli bi = 0;
    lli ni = 0;

    lli i, c;
    lli a,b;
    if(bipartita == false){
        cout << "Alice" << endl;
        //cout.flush();
        forn(xdddd, 0, n){
            cout << 1 << ' ' << 2 << endl;
            //cout.flush();
            cin >> i >> c;
        }
    }
    else{ 
        cout << "Bob" << endl;
        forn(xdddd, 0, n){
            cin >> a>> b;
            if((a==1 || b==1) && bi < bl){
                cout << blanco[bi] << ' ' << 1 << endl;
                //cout.flush();
                bi++;
                continue;
            }

            if((a==2 || b==2) && ni < neg){
                cout << negro[ni] << ' ' << 2 << endl;
                //cout.flush();
                ni++;
                continue;
            }

            if(bi<bl){
                lli coso = a;
                if(coso == 2) coso = b;
                cout << blanco[bi] << ' ' << coso << endl;
                //cout.flush();
                bi++;
                continue;
            }

            if(ni<neg){
                lli coso = a;
                if(coso == 1) coso = b;
                cout << negro[ni] << ' ' << coso << endl;
                //cout.flush();
                ni++;
                continue;
            }

        }
    }



}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}