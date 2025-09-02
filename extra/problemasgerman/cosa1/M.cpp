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
    vlli id(n);
    forn(i, 0, n) cin >> id[i];
    vlli prio(n);
    forn(i, 0, n) cin >> prio[i];

    minheap<pair<lli, lli>> minh;
    forn(i, 0, n){
        minh.push({prio[i], i});
    }

    forn(i, 0, n){
        auto xd = minh.top();
        minh.pop();
        cout << id[xd.second] << ' ';
    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t; while(t--) solve();
    return 0;
}