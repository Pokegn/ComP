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
    int n; cin >> n;
    int m,k; cin >> m >> k;

    vector<lli> mejores(0);
    vlli a(n);
    vlli b(m);
    lli suma = 0;
    lli resta = 0;
    vvlli minimum(n, vlli(m+1));
    forn(i, 0, n){
        cin >> a[i];
        suma+=a[i];
    }
    forn(i, 0, m) cin >> b[i];

    lli sz = 1<<m;
    
    vvlli opciones(m+1, vlli(0));
    vlli xd(1<<m, 0);
    forn(i, 0, sz){
        lli curr;
        if(__builtin_popcount(i)==1){
            curr = b[msb(i)];
            opciones[1].push_back(curr);
        }
        else{
            lli pot = 1<<msb(i);
            lli popc = __builtin_popcount(i);
            curr = xd[i^pot] & b[msb(i)];
            opciones[popc].push_back(curr);
        }
        xd[i]=curr;
    }

    // for(auto x : opciones[1]) cout << x << ' ';
    // cout << nl;
    // for(auto x : opciones[2]) cout << x << ' ';
    // cout << nl;
    // for(auto x : opciones[3]) cout << x << ' ';
    // cout << nl;
    // return;
    forn(i, 0, n){
        lli aa = a[i];
        forn(j, 1, m+1){
            lli mini = 1e18;
            for(auto x : opciones[j]){
                mini = min(mini, x&aa);
            }
            minimum[i][j] = mini;
        }
    }

    vector<lli> costs(0);
    forn(i, 0, n){
            costs.push_back(a[i]-minimum[i][1]);
        forn(j, 2, m+1){
            costs.push_back(minimum[i][j-1]-minimum[i][j]);
        }
    }

    sort(costs.begin(), costs.end(), greater<lli>());
    // for(auto x:minimum[0]) cout << x << ' ';
    // cout << nl;
    forn(i, 0, k) resta+=costs[i];
    cout << suma - resta << nl;
    return;
}

 
int main(){

    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}