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
    lli n; cin >> n;
    string s; cin >> s;
    vlli a(3*n, 0);
    vlli ans(n+1);
    ans[0] = 0;
    forn(i, 0, n) a[2*n+i] = (lli)(s[i]-'0');
    reverse(a.begin(), a.end());

    lli cola = 0;
    lli tamano = 0;
    forn(i, 1, n+1){ //quiero ver cuantos ocupo mover para que sea divisible por i
        if(ans[i-1] == -1){
            ans[i] = -1;
            continue;
        }
        ans[i] = ans[i-1];
        if(a[i-1] == 0) continue;
        else{
            cola = max(i-1, cola);
            while(a[cola] == 1){
                cola++;
            }
            ans[i] += cola-i+1;
            if(cola>=n) ans[i] = -1;
            a[cola] = 1;
            cola++;
        }
    }
    forn(i, 1, n+1){
        cout << ans[i]  << ' ';

    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}