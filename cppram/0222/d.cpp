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

lli cuantosunos(lli n){
    lli ans = 0;
    while(n>0){
        if(n%2 == 1) ans++;
        n/=2;
    }
    return ans;
}

void solve(){
    lli p,n; cin >> p >> n;
    vlli conexiones(2*1e6, 0);
    vvlli grafo(21, vlli(0));
    lli u, v;
    forn(i, 0, n){
        cin >> u >> v;
        grafo[u-1].pb(v-1);
    }
    vlli potenciasdos(25, 0);
    potenciasdos[0] = 1;
    forn(i, 1, 25){
        potenciasdos[i] = potenciasdos[i-1]*2;
    }

    lli ans = p;
    lli pot = 1;
    forn(i, 0, p){
        forn(j, pot, 2*pot){
            if(j == pot){
                forn(k, 0, grafo[i].size()){
                    conexiones[j] += potenciasdos[grafo[i][k]];
                }
            }
            else conexiones[j] = conexiones[j-pot]&conexiones[pot];
        }
        pot*=2;
    }

    forn(i, 0, potenciasdos[p]){
        ans = max(ans, cuantosunos(conexiones[i]) + cuantosunos(i));
    }
    // forn(i, 0, potenciasdos[p]){
    //     cout << conexiones[i] << nl;
    // }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}