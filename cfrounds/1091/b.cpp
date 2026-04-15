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
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i, 0, n) cin >> a[i];
    int idx; cin >> idx; idx--;
    int left = 0, right = 0;
    rep(i, 1, idx+1){
        if(a[i] != a[i-1]) left++;
    }
    rep(i, idx+1, n){
        if(a[i] != a[i-1]) right++;
    }
    if(left>0 && left%2 == 0) left--;
    if(right>0 && right%2 == 0) right--;
    int ans = 0;
    ans = max(left, right);
    if(ans%2 == 1) ans++;
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}