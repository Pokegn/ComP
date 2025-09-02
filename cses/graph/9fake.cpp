#include <bits/stdc++.h>
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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

lli dij(vector<vector<pair<lli, lli>>> &grafo, int k, int j){
    int n = grafo.size();
    minheap<pair<lli, lli>> minh; minh.push({0,k});
    vlli ans(n, -1);

    while(!minh.empty()){
        auto v = minh.top();
        minh.pop();

        if(v.second == j) return v.first;

        if(ans[v.second] != -1) continue;
        ans[v.second] = v.first;

        for(auto &u: grafo[v.second]){
            minh.push({ans[v.second] + u.first, u.second});
        } 
    }
    return -1;
}

void solve(){
    int n,m, q; cin >> n >> m >> q;
    int k,j;
    vector<vector<pair<lli, lli>>> grafo(n, vector<pair<lli, lli>> {});
    lli a,b,c;
    forn(i, 0, m){
        cin >> a >> b >> c;
        grafo[a-1].push_back({c, b-1});
        grafo[b-1].push_back({c, a-1});
    }
    

    forn(i, 0, q){
        cin >> k >> j;
        cout << dij(grafo, k-1, j-1) << '\n';
    }    
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}