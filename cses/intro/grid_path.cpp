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

vector<vector<int>> neigh;

bool isConnected(vi a){
    
    vector<bool> vis(49, false);
    for(auto x: a) vis[x] = true;
    int count = 0;
    queue<int> bfs;
    bfs.push(42);
    vis[42] = true;
    while(!bfs.empty()){
        int bfssz = bfs.size();
        while(bfssz--){
            int u = bfs.front();
            bfs.pop();
            count++;
            
            for(auto v: neigh[u]){
                if(vis[v]) continue;
                bfs.push(v);
                vis[v] = true;
            }
        }
    }
    
    int n = 49 - sz(a);
    if(count < n) return false;
    return true;

}

void solve(){
    string s; cin >> s;
    vector<vector<int>> caminos;
    caminos.push_back({0});

    neigh = vector<vector<int>>(49);

    rep(b, 0, 49){
        if(b%7 > 0){
            neigh[b].push_back(b-1);
        }
        if(b%7 < 6){
            neigh[b].push_back(b+1);
        }
        if(b-7 >= 0){
            neigh[b].push_back(b-7);
        }
        if(b+7 < 49){
            neigh[b].push_back(b+7);
        }
    }

    rep(iii, 0, 47){
        vector<vector<int>> newcaminos;
        for(auto cam: caminos){
            vector<bool> vis(49, false);
            for(auto v: cam) vis[v] = true;

            int b = cam.back();
            for(auto c: neigh[b]){
                if(vis[c]) continue;
                if(c == 42) continue;
                cam.push_back(c);
                if(isConnected(cam)){
                    newcaminos.push_back(cam);
                }
                cam.pop_back();
            }
        }
        std::swap(newcaminos, caminos);
    }    
    cout << "{";
    for(auto cam: caminos){
        cout << "{";
        for(auto x: cam){
            cout << x << ", ";
        }
        cout << "42}, ";
    }
    cout << "}";
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}