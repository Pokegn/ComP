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
    int n; cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vector<int> b;
    rep(i, 0, n){
        if(a[i] != i+1) b.push_back(a[i]);
    }
    reverse(all(b));
    int idx = 0;
    rep(i, 0, n){
        if(a[i] != i+1){
             a[i] = b[idx];
             idx++;
        }
    }

    rep(i, 0, n){
        if(a[i] != i+1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}