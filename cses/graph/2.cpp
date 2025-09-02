//https://cses.fi/problemset/task/1193
#include <bits/stdc++.h> //(En cuadricula) bfs para encontrar menor camino entre dos vertices
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

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> tabla(n, vector<char>(m));
    pair<int, int> A,B;
    forn(i, 0, n){
        forn(j, 0, m){
            cin >> tabla[i][j];
            if(tabla[i][j] == 'A') A = {i, j};
            if(tabla[i][j] == 'B') B = {i, j};
        }
    }

    vector<vector<char>> padre(n, vector<char>(m, 'x'));
    int depth = 0;
    int dep;
    int br  = 0;
    //vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> bfs; bfs.push({B.first, B.second});
    tabla[B.first][B.second] = '#';
    while(!bfs.empty()){
        int bfssz = bfs.size();
        while(bfssz--){
            pair<int, int> u = bfs.front();
            bfs.pop();

            for(int i=u.first-1; i<=u.first+1; i+=2){
                if(i<0 || i>n-1) continue;
                if(tabla[i][u.second] == '.' || tabla[i][u.second] == 'A'){
                    bfs.push({i, u.second});
                    if(i<u.first) padre[i][u.second] = 'D';
                    else padre[i][u.second] = 'U';
                    if(tabla[i][u.second] == 'A'){
                        br = 1;
                    }
                    tabla[i][u.second] = '#';
                }
            }

            for(int j=u.second-1; j<=u.second+1; j+=2){
                if(j<0 || j>m-1) continue;
                if(tabla[u.first][j] == '.' || tabla[u.first][j] == 'A'){
                    bfs.push({u.first, j});
                    if(j<u.second) padre[u.first][j] = 'R';
                    else padre[u.first][j] = 'L';
                    if(tabla[u.first][j] == 'A'){
                        br = 1;
                    }
                    tabla[u.first][j] = '#';
                }
            }
        }
        depth++;
        if(br == 1) break;
    }





     

        int x= A.first;
        int y= A.second;
        if(padre[x][y] == 'x'){
            cout << "NO" <<nl;
            return;
        }
        else{
            cout << "YES" << nl << depth << nl;
        }
        while(x!=B.first || y!=B.second){
            cout << padre[x][y];
            switch (padre[x][y])
            {
            case 'U':
                x-=1;
                break;
            case 'D':
                x+=1;
                break;
            case 'L':
                y-=1;
                break;
            case 'R':
                y+=1;
                break;
            }
        }
        cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}