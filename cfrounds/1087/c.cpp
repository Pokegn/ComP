#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
// #define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    int idx = -1;
    int res;
    rep(i, 0, n-1){
        cout << "? " << 2*i+1 << ' ' << 2*i+2 << endl;
        cin >> res;
        if(res == 1) idx = 2*i+1;
    }
    cout << "? " << 2*n-1 << ' ' << 2*n-2 << endl; cin >> res; if(res == 1) idx = 2*n-1;
    cout << "? " << 2*n-3 << ' ' << 2*n-1 << endl; cin >> res; if(res == 1) idx = 2*n-1;

    if(idx == -1){
        cout << "! " << 2*n << endl;
        return;
    }

    cout <<"! " << idx << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}