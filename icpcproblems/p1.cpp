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

vector<vector<int>> grafo;
vector<bool> dfs_vis;

void solve(){
    int n; cin >> n;
	grafo.assign(2*n+1, {});

    string s1, s2; cin >> s1 >> s2;
    vlli todos(2*n, 0);
    forn(i, 0, n){
        if(s1[i] == '.') todos[i] = 1;
    }
    forn(i, n, 2*n){
        if(s2[i-n] == '.') todos[i] = 1;
    }

    forn(i, 0, n){
        if(s1[i] == '.' && s2[i] == '.'){
            grafo[i].push_back(n+i);
		    grafo[n+i].push_back(i);
        }
        if(i%n>0){
            if(s1[i] == '.' && s1[i-1] == '.'){
                grafo[i].push_back(i-1);
                grafo[i-1].push_back(i);
            }
            if(s2[i] == '.' && s2[i-1] == '.'){
                grafo[n+i].push_back(n+i-1);
                grafo[n+i-1].push_back(n+i);
            }
        }
        if((i%n+1)<n){
            if(s1[i] == '.' && s1[i+1] == '.'){
                grafo[i].push_back(i+1);
                grafo[i+1].push_back(i);
            }
            if(s2[i] == '.' && s2[i+1] == '.'){
                grafo[n+i].push_back(n+i+1);
                grafo[n+i+1].push_back(n+i);
            }
        }
    }
    n = 2*n;

    vector<bool> bfs_vis(n+1, false);
    queue<int> bfs;
    lli count = 0;
    forn(i, 0, n){
        if(bfs_vis[i]) continue;
        if(todos[i] == 0) continue;
        count = 1;
        bfs.push(i); bfs_vis[i] = true;
        
        while(!bfs.empty()) {
            int bfssz = bfs.size();
            while(bfssz--) {
                int u = bfs.front();
                bfs.pop();
    
                for(int v : grafo[u]){
                    if(!bfs_vis[v]) {
                        count++;
                        bfs.push(v);
                        bfs_vis[v] = true;
                    }
                }


            }
        }
        
        if(count%2 == 1){
            cout << "None" << nl;
            return;
        }
    }

    n = s1.length();
    vvlli a(2, vlli(n));
    forn(i, 0, n){
        if(s1[i] == '.') a[0][i] = 1;
        else a[0][i] = 0;

        if(s2[i] == '.') a[1][i] = 1;
        else a[1][i] = 0;
    }

    lli num = 2;
    forn(i, 0, n){
        if(a[0][i] == 1 && a[1][i] == 1){
            a[0][i] = num;
            a[1][i] = num;
            num++;
            continue;
        }
        if(a[0][i] == 1 && a[1][i] != 1){
            if(i+1 >= n || a[0][i+1] == 0){
                cout << "None" << nl;
                return;
            }
            a[0][i] = num;
            a[0][i+1] = num;
            num++;
            continue;
        }
        if(a[0][i] != 1 && a[1][i] == 1){
            if(i+1 >= n || a[1][i+1] == 0){
                cout << "None" << nl;
                return;
            }
            a[1][i] = num;
            a[1][i+1] = num;
            num++;
            continue;
        }
        if(a[0][i] != 1 && a[1][i] != 1){
            continue;
        }
    }

    bool xd = false;
    forn(i, 0, n-1){
        if(a[0][i] ==0 || a[0][i+1] ==0) continue;
        if(a[0][i] == a[1][i] && a[0][i+1] == a[1][i+1]) xd = true;
    }

    if(xd){
        cout << "Multiple" << nl;
    }
    else{
        cout << "Unique" << nl;
    }
    return;
    forn(i, 0, n){
        cout << a[0][i] << ' ';
    }
    cout << nl;
    forn(i, 0, n){
        cout << a[1][i] << ' ';
    }
    cout << nl;

}



int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}