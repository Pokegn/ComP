#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    int ki;
    vector<vector<int>> grafo(n);
    vector<int> ksize(n);
    vector<vector<int>> dependencias(n);
    rep(i, 1, n+1){
        cin >> ki;
        ksize[i-1] = ki;
        rep(j, 1, ki+1){
            int x; cin >> x;
            grafo[x-1].push_back(i-1);
            dependencias[i-1].push_back(x-1);
        }
    }

    vector<int> in_degree(n);
    for(const vector<int> &nodes : grafo){
        for(int node : nodes) in_degree[node]++;
    }

    queue<int> q;
    rep(i, 0, n) if(in_degree[i] == 0) q.push(i);

    vector<int> top;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        top.push_back(curr);
        for(auto next: grafo[curr]) if (--in_degree[next] == 0) q.push(next);
    }

    

    if(top.size() == n){
        vector<int> read(n, 1); //read[i] tiene la leida del actual vertice i
        rep(i, 0, n){ //top[i] es el actual vertice
            for(auto d: dependencias[top[i]]){ //d es el actual vertice, top[d] es 
                int minread = (d < top[i] ? read[d] : read[d]+1);
                read[top[i]] = max(read[top[i]], minread);
            }
        }
        int ans = 0;
        // rep(i, 0, n) cout << read[i] << ' ';
        // cout << endl;
        rep(i, 0, n) ans = max(ans, read[i]);
        cout << ans << endl;

        // rep(i, 0, n-1) cout << top[i]+1 << ' ';
        // cout << top.back() + 1 << endl;
    }
    else{
        cout << -1 << endl;
    }
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}