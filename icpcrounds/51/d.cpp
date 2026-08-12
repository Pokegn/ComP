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
    vector<int> a(n+1); rep(i, 1, 1+n) cin >> a[i];
    sort(all(a));
    
    pair<ll,ll> ans[n+1]; ans[0] = {0,0}; //cuantos tengo y en que momento
    for(ll i = 1; i < n+1; i++){
        ll bases = i;
        ll soldados = ans[i-1].fi;
        ll momento = ans[i-1].se;
        ll need = (a[i]-soldados)/i; if((a[i]-soldados)%i != 0) need++;
        if(a[i]-soldados <= 0) need = 0;
        ans[i] = {soldados + i*need - a[i],momento+need};
    }

    ll ret = m;
    for(int i = 1; i < n+1; i++){
        //si decido armar i bases
        if(ans[i].se > m) continue;
        ret = max(ret, ans[i].fi + (m - ans[i].se)*(i+1));
    }
    cout << ret <<endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}