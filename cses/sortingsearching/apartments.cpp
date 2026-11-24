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
    int n,m,k; cin >> n >> m >> k;
    vi a(n); rep(i,0,n) cin >> a[i];
    vi b(m); rep(i, 0, m) cin >> b[i];
    sort(all(a)); sort(all(b));
    int ai = 0;
    int bi = 0;
    int ans = 0;
    while(ai < n && bi < m){
        if(a[ai] - k > b[bi]){
            bi++; continue;
        }
        if(a[ai] + k < b[bi]){
            ai++; continue;
        }
        ans++, ai++, bi++;
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}