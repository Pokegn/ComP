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

bool tries(ll n, ll m){ //se puede o no
    ll count = 0;
    rep(i, 1, n+1){
        count += (m/i)*i;
    }
    if(count >= n) return true;
    return false;
}

void solve(){
    ll n; cin >> n;

    ll l = 0, r = n;
    while(l<r){
        ll m = (l+r)/2;
        if(tries(n, m)){
            r = m;
        }
        else{
            l = m+1;
        }
    }

    cout << l << endl;
    vector<ll> caben(n+1, 0);
    rep(i, 1, n+1){
        caben[i] = l/i;
    }

    vector<ll> ans;
    ll curr = 1;
    rep(i, 1, n+1){
        rep(j, 0, caben[i]){
            rep(k, 0, i) ans.push_back(curr);
            curr++;
        }
    }

    ll sizee = sz(ans);
    ll primero = ans[sizee-n];
    rep(i, sizee-n, sizee) cout << ans[i]+1-primero << ' ';
    cout << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}