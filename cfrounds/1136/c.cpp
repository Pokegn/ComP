#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
// #define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ll f(ll n, ll x){
    ll ans = (n/x)-1;
    if(n%x != 0) ans++;
    return ans;
}

void solve(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll>a(n); rep(i,0,n) cin >> a[i];
    sort(all(a));

    int idx = n-2;
    while(idx > 0 && a[idx-1] == a[idx]) idx--;

    ll ans = (a[idx]/x)-1;
    if(a[idx]%x != 0) ans++;

    ll mult = ans; //de x*mult+1 a x*(mult+1)
    // cout << ans << ' ';

    ll curr = f(a[idx], x);

    for(int i = idx-1; i>=0; i--){
        if(f(a[i], x) < curr){
            ans--;
            curr--;
        } 
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}