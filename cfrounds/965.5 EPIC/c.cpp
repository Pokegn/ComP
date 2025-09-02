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
    vector<pair<lli, lli>> c(n);
    forn(i, 0, n) cin >> c[i].first >> c[i].second;

    pair<lli, lli> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    bool gana = true;
    forn(i, 0, n){
        if((end.first-start.first)*(end.first-start.first)+(end.second-start.second)*(end.second-start.second) >= 
                (end.first-c[i].first)*(end.first-c[i].first)+(end.second-c[i].second)*(end.second-c[i].second)){
                    gana = false;
                }
    }

    if(gana == true){
        cout << "YES" << nl;
    }
    else cout << "NO" << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}