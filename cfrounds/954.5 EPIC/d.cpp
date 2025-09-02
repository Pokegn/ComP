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
    int n; cin >> n;
    vi a(n); forn(i, 0, n) cin >> a[i];
    vlli mintu(n+1, 1e10); //minimo de turnos gastados para bloquear i pasteles
    
    vi rep(5001, 0);
    forn(i, 0, n) rep[a[i]]++;
    int num = 0;
    vi sorted;
    forn(i, 0, 5001) if(rep[i]!=0){
        num++;
        sorted.push_back(i);
    }
    vlli mintu_temp(n+1);

    mintu[0] = 0;
    forn(i, 0, num){ //i representa hasta que weon nos estamos tomando
        forn(j, 0, num+1) mintu_temp[j] = mintu[j];

        forn(j, 1, num+1){
            if(i-j+2 > mintu[j-1]+rep[sorted[i]]){
                mintu_temp[j] = min(mintu_temp[j], mintu[j-1]+rep[sorted[i]]);
                //cout << i << ' ' << j << nl;
            }
        }

        forn(j, 0, n+1) mintu[j] = mintu_temp[j];
    }

    int ans = 0;
    forn(i, 1, num+1){
        if(mintu[i]!=1e10) ans = i;
    }
    //forn(i, 0, n+1) cout << mintu[i] << ' ';
    cout << num-ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}