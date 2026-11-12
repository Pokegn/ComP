#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<char>> ans(n, vector<char>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            set<char> pos = {'A', 'B', 'C', 'D'};
            if(i > 0) pos.erase(ans[i-1][j]);
            if(j > 0) pos.erase(ans[i][j-1]);
            pos.erase((char)a[i][j]);
            ans[i][j] = *(pos.begin());
        }
    }
    rep(i, 0, n){
        rep(j, 0, m) cout << ans[i][j];
        cout << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}