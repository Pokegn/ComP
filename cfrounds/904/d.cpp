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
    lli  n; cin >> n;
    vlli a(n); forn(i, 0, n) cin >> a[i];
    vector<bool> pared(n, false);
    forn(i, 0, n){
        if(a[i]>4 || a[i] == 0) pared[i] = true;
    }
    
    lli ahorros = 0;
    forn(i, 0, n) if(a[i] == 0) ahorros++;
    lli curr = -1;
    
    lli j = 0;
    while(j<=n){
        if(a[j] >0 && a[j]<=2){
            curr = j;
            j++;
            while(a[j]>2 || a[j] == 0){
                if(pared[j]){
                    break;
                }
                j++;
            }
            if(j%2 == curr%2){
                curr = j;
                continue;
            }
            else{
                ahorros++;
            }
        }
        j++;
    }

    cout << n-ahorros << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}