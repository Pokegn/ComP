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
vector<string> caminos;
vector<int> needfirst(49, 0);

bool isConnected(vi &a, vector<bool> &visa){
    
    vector<bool> vis = visa;
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

//de sz 24 son 871066
// set<pair<ll, ll>> lol;

void getCaminos(vector<int> &camino, vector<bool> &vis, int val){
    // cout << val << ' ';
    if(sz(camino) == 48){
        // ll visi = 0;
        // rep(i, 0, 48) if(vis[i]) visi += (1<<i);
        // lol.insert({visi, val});
        // cout << "yipi ";
        camino.push_back(42);
        string chemin = "";
        rep(i, 1, 49){
            if(camino[i] - camino[i-1] == 1) chemin += 'R';
            if(camino[i] - camino[i-1] == -1) chemin += 'L';
            if(camino[i] - camino[i-1] == 7) chemin += 'D';
            if(camino[i] - camino[i-1] == -7) chemin += 'U';
        }
        caminos.push_back(chemin);
        camino.pop_back();
        return;
    }

    //if(!isConnected(camino, vis)) return;
    vi unos;
    for(auto v: neigh[val]){
        if(vis[v]) continue;
        if(v == 42) continue;
        int available = 0;
        for(auto w: neigh[v]){
            if(!vis[w]) available++;
        }
        if(available == 1) unos.push_back(v);
    }

    if(sz(unos) > 1) return;
    if(sz(unos) == 1){
        auto v = unos[0];
        if(vis[v]) return;
        if(!vis[needfirst[v]]) return;
        if(v == 42) return;
        camino.push_back(v);
        vis[v] = true;
        getCaminos(camino, vis, v);
        camino.pop_back();
        vis[v] = false;
        return;
    }

    for(auto v: neigh[val]){
        if(vis[v]) continue;
        if(!vis[needfirst[v]]) continue;
        if(v == 42) continue;
        camino.push_back(v);
        vis[v] = true;
        getCaminos(camino, vis, v);
        camino.pop_back();
        vis[v] = false;
    }
}

void fillNeedfirst(){
    rep(i, 1, 7) needfirst[i] = i-1;
    rep(i, 1, 7) needfirst[7*i] = 7*i-7;
    rep(i, 1, 7) needfirst[7*i+6] = 7*i-1;
    rep(i, 0, 6) needfirst[42+i] = 43+i;
}

void fillneigh(){
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
}


void solve(){
    string s; cin >> s;
    caminos = vector<string>(0);

    neigh = vector<vector<int>>(49);
    fillneigh();
    fillNeedfirst();

    vector<int> camino = {0};
    vector<bool> vis(49, false); vis[0] = true;

    getCaminos(camino, vis, 0);
    // cout << sz(lol) << endl;

    // cout << sz(caminos) << endl;

    int ans = 0;
    for(auto cam: caminos){
        bool good = true;
        rep(i, 0, 48){
            if(s[i] != '?' && s[i] != cam[i]) good = false;
        }
        if(good) ans++;
    }
    cout << ans << endl;
    return;


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}