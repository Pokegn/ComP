#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define endl '\n'
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vvi a(n, vi(n));
    
    rep(i, 0, n){
        rep(j, 0, n){
            int mex = 0;
            vi count(2*n+1, 0);
            rep(ii, 0, i) count[a[ii][j]]++;
            rep(jj, 0, j) count[a[i][jj]]++;
            while(count[mex] > 0) mex++;
            a[i][j] = mex;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}