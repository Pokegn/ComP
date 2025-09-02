//https://cses.fi/problemset/task/1197
#include <bits/stdc++.h> //bellman-ford pero sin la cosa rara de al final como en el 10.cpp, pero ahora incluye
            //el arreglo vis (visitado) y para cualquier cantidad de componentes conexas :) en la misma complejida
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, m; cin >> n >> m;
    vector<vector<lli>> grafo(n, vector<lli>(3));
    lli a,b,c;
    forn(i, 0, m){
        cin >> a>> b>> c;
        grafo.push_back({a-1,c,b-1});
    }

    lli x;
    vector<lli> ans(n, 1e16); ans[0] = 0;
    vector<lli> parent(n, -1);
    vector<bool> vis(n, false); vis[0] = true; 
    lli j = 0;

    forn(i, 0, n){
        x = -1;
        for(auto v: grafo){
            if(vis[v[0]]){
                if(ans[v[2]] > ans[v[0]]+v[1]){
                    ans[v[2]] = max((lli)-1e16, ans[v[0]]+v[1]);
                    x = v[2];
                    parent[v[2]] = v[0];
                    vis[v[2]] = true;
                }
            }
        }
        if(x == -1){
            while(vis[j]) j++;
            if(j<n){
                vis[j] = 1;
                ans[j] = 0;
            }
        }
    }

    if(x == -1){
        cout << "NO" << nl;
        return;
    }
    else{
        cout << "YES" << nl;
        int xd = x;
        forn(i, 0, n) xd = parent[xd];
        vector<int> ciclo;
        ciclo.push_back(xd);
        //cout << xd << ' ';
        x = xd;
        xd = parent[xd];
        while(xd != x){
            //cout << xd << ' ';
            ciclo.push_back(xd);
            xd = parent[xd];
        }
        ciclo.push_back(x);
        reverse(ciclo.begin(), ciclo.end());
        int sz = ciclo.size();
        forn(i, 0, sz) cout << ciclo[i]+1 << ' ';
        cout << nl;
    }
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}