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
string s;

void solve(){
    int n; cin >> n;
    cout << s << endl;
    int idx; cin >> idx;
    ll ans = idx/3;
    cout << n + ans -1 << endl;
    return;
}


int main(){
    // cin.tie(0)->sync_with_stdio(false);
    s+="++-";
    rep(i, 0, 200) s+="+--";
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}