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
    int sum1 = 0, sum2 = 0;
    int n; cin >> n; int k; cin >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) sum1 += a[i];
    rep(i, 0, n) sum2 += k;
    if(sum1%2 == 1 || sum2%2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}