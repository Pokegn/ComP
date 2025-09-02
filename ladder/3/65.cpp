#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vi a(n);
    vi tot(n); //cuanto te suma si lo volteas
    for(int &x: a) cin >> x;
    tot[0] = (a[0] == 1 ? -1:1); 
    int sum = 0;
    forn(i, 0, n){
        sum+=a[i];
        if(i>0){
            if(a[i]==1) tot[i] = tot[i-1] -1;
            else tot[i] = tot[i-1]+1;
        }
    }


    int min;
    int maxv = (a[0] == 1 ? -1:1);

    forn(i, 1, n){
        min = 0;
        forn(j, 0, i-1){
            if(tot[j] < min) min = tot[j];
        }
        maxv = max(maxv, tot[i]-min);
    }
    cout << maxv + sum << nl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}