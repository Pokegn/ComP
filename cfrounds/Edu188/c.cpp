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
    ll a,b,c; cin >> a >> b >> c;
    ll m; cin >> m;
    vector<ll> ans(3, 0);
    ans[0] += 6*(m/a);
    ans[1] += 6*(m/b);
    ans[2] += 6*(m/c);
    ans[0] -= 3*(m/lcm(a,b));
    ans[0] -= 3*(m/lcm(a,c));
    ans[0] += 2*(m/lcm(a,lcm(b,c)));
    
    ans[1] -= 3*(m/lcm(c,b));
    ans[1] -= 3*(m/lcm(a,b));
    ans[1] += 2*(m/lcm(a,lcm(b,c)));

    ans[2] -= 3*(m/lcm(c,b));
    ans[2] -= 3*(m/lcm(a,c));
    ans[2] += 2*(m/lcm(a,lcm(b,c)));

    rep(i, 0, 3) cout << ans[i] << ' ';
    cout << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}