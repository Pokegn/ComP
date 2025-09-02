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

vlli cunt(1e6+1, 0);

void solve(){ //hago menos de 10 a la 7 operaciones
    lli n; cin >> n;
    vlli a(n);
    forn(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    forn(i, 0, n) cunt[a[i]]++;

    lli ans = 0;
    forn(i, 2, 1001){
        for(lli j = 0; (a[j]*i*i<=1e6 && j<n) ; j++){
            ans+=cunt[a[j]*i]*cunt[a[j]*i*i];
        }
    }
    forn(i, 0, n){
        if(cunt[a[i]]>=3){
            lli xd = cunt[a[i]];
            ans+=((xd-1)*(xd-2));
        }
    }
    cout << ans << nl;
    forn(i, 0, n) cunt[a[i]]=0;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}