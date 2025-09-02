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
    lli n; cin >> n;
    vlli a(n); forn(i,0, n) cin >> a[i];
    lli maxi = 0;
    forn(i, 0, n) maxi = max(maxi, a[i]);
    vlli imp, par;
    forn(i, 0, n){
        if(a[i]%2 == 0) par.pb(a[i]);
        else imp.pb(a[i]);
    }

    lli suma = 0;
    forn(i, 0, n) suma+=a[i];

    sort(par.begin(), par.end());
    sort(imp.begin(), imp.end());
    lli parsz = par.size(), impsz = imp.size();

    if(parsz == 0 || impsz == 0){
        cout << maxi << nl;
        return;
    }
    
    lli ans = 0;

    cout << suma-impsz+1 << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}