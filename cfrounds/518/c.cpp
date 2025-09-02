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

void solve(){
    lli n, m; cin >> n >> m;
    vvlli puntos(n+1, vlli(0));

    vector<bool> esta(n+1, false);
    forn(i, 1, m+1){
        lli u, v; cin >> u >> v;
        esta[u] = true;
        esta[v] = true;
        puntos[v].push_back(i);
        puntos[u].push_back(i);
    }

    forn(i, 1, n+1){
        if(puntos[i].size() == 0){
            cout << 1 << nl;
            cout << i << ' ' << m + i << nl;;
            continue;
        }
        cout << puntos[i].size() << nl;
        forn(j, 0, puntos[i].size()){
            cout << i << ' ' << puntos[i][j] << nl;
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    while(t--) solve();
    return 0;
}