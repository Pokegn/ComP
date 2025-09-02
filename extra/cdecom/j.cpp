#include <bits/stdc++.h>
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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<lli>> tabla(1010, vlli(8, 0));
vlli resultados;
map<string, int> ind;
vector<string> nombre = {""};

bool compare(string a, string b){
    if(resultados[ind[a]] != resultados[ind[b]]) return resultados[ind[a]] > resultados[ind[b]];
    int la, lb; la = a.length(); lb = b.length();
    int sz = min(la, lb);
    forn(i, 0, sz){
        if(a[i]!=b[i]) return a[i] < b[i];
    }
    return la < lb;
}

void solve(){
    int n; cin >> n; int indice = 1;
    int xd =0 ;
    string par; char pro; lli pun;


    while(n--){
        cin >> par >> pro >> pun;
        if(ind[par] == 0){
            ind[par] = indice;
            indice++;
            nombre.push_back(par);
        }
        xd = ind[par];
        tabla[xd][(int)(pro-'A')] = max(tabla[xd][(int)(pro-'A')], pun);
        //cout << tabla[xd][2] << '\n';
    }


    resultados.assign(indice, 0);
    forn(i, 1, indice){
        forn(j, 0, 8)
        resultados[i] += tabla[i][j];
    }

    sort(nombre.begin()+1, nombre.end(), compare);
    forn(i, 1, 5){
        cout << nombre[i] << nl;
    }


    
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}