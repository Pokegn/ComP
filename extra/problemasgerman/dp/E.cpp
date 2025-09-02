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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n,w; cin >> n >> w;
    vlli u(n), v(n);
    forn(i, 0, n){
        cin >> u[i]; //u es pesos
        cin >> v[i]; //v valores
    }
    vlli minpeso(1000*n + 1, 0);
    forn(i, 0, n){
        rof(j, 1000*n + 1, 0){
            if((minpeso[j] > 0 || j == 0)){
                if(minpeso[j+v[i]]!=0) minpeso[j+v[i]] = min(minpeso[j]+u[i], minpeso[j+v[i]]);
                else minpeso[j+v[i]] = minpeso[j]+u[i];
            }
        }
    }

    lli ans = 0;
    forn(i, 0, 1000*n+1){
        if(minpeso[i] > 0 && minpeso[i] <= w){
            ans = i;
        }
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}