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
vector<vector<int>> caminos;
vector<int> needfirst(49, -1);
const int N = 4500000;

vector<vector<int>> trie(N+1, vector<int>(49,0));
int trie_pos = 0;
bool final[N + 1];

void getCaminos(vector<int> &camino, vector<int> &vis, int val){
    if(sz(camino) == 48){
        camino.push_back(42);
        caminos.push_back(camino);
        camino.pop_back();
    }

    for(auto v: neigh[val]){
        if(vis[v]) continue;
        if(v == 42) continue;
        if(needfirst[v] != -1  && !vis[needfirst[v]]) continue;
        camino.push_back(v);
        vis[v] = true;
        getCaminos(camino, vis, v);
        camino.pop_back();
        vis[v] = false;
    }
}

void fillNeedfirst(){
    rep(i, 1, 7) needfirst[i] = i-1;
    rep(i, 1, 7) needfirst[7*i] = i-7;
    rep(i, 1, 7) needfirst[7*i+6] = i-7;
    rep(i, 0, 6) needfirst[42+i] = i+1;
}

bool isConnected(vi &a){
    
    vector<bool> vis(49, false);
    vector<bool> vis2 = vis;
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

    // int alone = 0;
    // rep(i, 0, 49){
    //     if(vis2[i]) continue;
    //     int counti = 0;
    //     for(auto j: neigh[i]) if(!vis2[j]) count++;
    //     if(counti == 1) alone++;
    // }

    // if(alone > 2) return false;
    
    int n = 49 - sz(a);
    if(count < n) return false;
    return true;

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
    vector<vector<int>> caminos = {{0}};

    neigh = vector<vector<int>>(49);
    fillneigh();
    fillNeedfirst();

    vector<int> camino = {0};
    vector<int> vis(49, 0); vis[0] = true;

    getCaminos(camino, vis, 0);

    cout << sz(caminos) << endl;
    for(auto cam: caminos){
        for(auto x: cam) cout << x << ' ';
        cout << endl;
    }
    return;

    // rep(iii, 0, 47){
    //     vector<vector<int>> newcaminos;
    //     for(auto cam: caminos){
    //         vector<bool> vis(49, false);
    //         for(auto v: cam) vis[v] = true;

    //         int b = cam.back();

    //         for(auto c: neigh[b]){
    //             if(vis[c]) continue;
    //             if(c == 42) continue;
    //             if(c < 7 && !vis[c-1]) continue;
    //             if(c%7 == 6 && c > 6 && !vis[c-7]) continue;
    //             if(c>=42 && c < 48 && !vis[c+1]) continue;
    //             cam.push_back(c);
    //             if(isConnected(cam)){
    //                 newcaminos.push_back(cam);
    //             }
    //             cam.pop_back();
    //         }
    //     }
    //     std::swap(newcaminos, caminos);
    //     // cout << caminos.size() << endl;
    // }    
    // for(auto cam:caminos) cam.push_back(42);


    for(auto cam: caminos) {
        int node = 0;
        for (int i = 0; i < 24; i++) {
            int idx = cam[i];
            if (trie[node][idx] == 0) {
                trie[node][idx] = ++trie_pos;
            }
            node = trie[node][idx];
        }
        final[node] = true;
    }

    rep(i, 0, trie_pos){
        cout << "{";
        rep(j, 0, 49) if(trie[i][j] > 0) cout << trie[i][j] << ",";
        cout << "}";
    }
    // cout << trie_pos << endl;
    return;





    

    // cout << '{';
    // for(auto c: caminos){
    //     cout << '\"';
    //     string add = "";
    //     rep(i, 1, 49){
    //         if(c[i] - c[i-1] == 1) add+="R";
    //         if(c[i] - c[i-1] == -1) add+="L";
    //         if(c[i] - c[i-1] == 7) add+="D";
    //         if(c[i] - c[i-1] == -7) add+="U";
    //     }
    //     cout << add << "\", ";
    // }  
    // cout << '}'; 

    // set<vector<int>> caminos2;
    // for(auto cam: caminos){
    //     vi c;
    //     rep(i, 0, 14) c.push_back(cam[i]);
    //     caminos2.insert(c);
    // }

    //return;
    cout << "{";
    for(auto cam: caminos){
        cout << "{";
        rep(i, 0, 48) cout << cam[i] << ",";
        cout << 42;
        cout << "},";
    }
    cout << "};";
    cout << endl;


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}