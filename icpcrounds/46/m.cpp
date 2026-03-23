#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,k ; cin >> n >> k;
    set<int> s;
    rep(i, 0, n) s.insert(i);
    s.insert(-2*n-2);
    s.insert(2*n+2);

    rep(i, 0, k){
        ll h; cin >> h;
        int l, r; 
        auto it = s.lower_bound(h);
        r = *it;
        if(r == h) l = h;
        else l = *prev(it); 
        if(h-l  <= r-h){ s.erase(l); cout << l << endl;}
        else{ cout << r << endl; s.erase(r);}
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}
