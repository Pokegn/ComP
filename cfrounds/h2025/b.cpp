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
    lli n, k; cin >> n >> k;
    vlli a(n); forn(i, 0, n) cin >> a[i];
    map<lli, lli> count;
    vlli values;
    forn(i, 0, n){
        if(count[a[i]] == 0) values.push_back(a[i]);
        count[a[i]]++;
    }

    lli sz = values.size();
    vlli valuesordered;
    forn(i, 0, sz) valuesordered.push_back(count[values[i]]);
    sort(valuesordered.begin(), valuesordered.end());

    lli xd = 0;
    forn(i, 0, sz-1){
        if(k >= valuesordered[i]){
            k-=valuesordered[i];
            xd++;
        }
    }

    cout << sz-xd << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}