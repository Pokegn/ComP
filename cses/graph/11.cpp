//https://cses.fi/problemset/task/1195/
#include <bits/stdc++.h> //el dijkstra de 8.cpp en log(mlog(m)), pero ahora con la posibilidad de dividir entre dos
        //una arista del grafo. Para esto separamos las entradas del minheap en dos, uno con el camino sin arista cambiada 
        //y otro con la arista cambiada. En cada paso consideramos el caso donde se cambia de un tipo a otro y lo guardamos
        //en dos arreglos distintos. La complejidad es la misma.
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
    int n, m; cin >> n >> m;
    vector<vector<pair<lli, lli>>> grafo(n);
    int a,b,c;
    forn(i, 0, m){
        cin >> a>> b>> c;
        grafo[a-1].push_back({c, b-1});
    }

    minheap<pair<lli, pair<lli, lli>>> minh; minh.push({0,{0, 2}}); //quien, tipo de query
    vector<lli> ans1(n, -1);
    vector<lli> ans2(n, -1);
    lli trueans = 1e16;

    while(!minh.empty()){ //v.first es la respuesta, v.second.first es de quien, v.second.second es de que tipo es
        auto v = minh.top(); minh.pop();

        if(v.second.second == 1 && ans1[v.second.first] == -1){
            ans1[v.second.first] = v.first;

            for(auto u: grafo[v.second.first]){
                minh.push({ans1[v.second.first] + u.first, {u.second, 1}});
            }
            continue;
        }

        //v.first es la respuesta, v.second.first es de quien, v.second.second es de que tipo es
        if(v.second.second == 2 && ans2[v.second.first] == -1){
            ans2[v.second.first] = v.first;

            for(auto u:  grafo[v.second.first]){
                //primero si sigo sin cambio
                minh.push({ans2[v.second.first] + u.first, {u.second, 2}});
                //ahora con cambio
                minh.push({ans2[v.second.first] + u.first/2, {u.second, 1}});
            }
        }
    }
    std::cout << ans1[n-1] << nl;
    return;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}