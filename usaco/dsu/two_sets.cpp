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

const int MAXN = 1e6+2;
map<ll, ll> ans;
map<ll, bool> vis;
map<ll, ll> p;
ll a,b;

void dfs(ll x, ll s){
    if(vis[x]) return;
    vis[x] = true;
    ans[x] = s;

    if(p[a-x] == 1){
        dfs(a-x, s);
    }

    if(p[b-x] == 1){
        dfs(b-x, s);
    }
}

void solve(){
    ll n; cin >> n >> a >> b;
    vector<ll> vals;
    rep(i, 0, n){
        ll x; cin >> x;
        p[x] = 1;
        vals.push_back(x);
    }
    
    rep(i, 0, n){
        if(p[a-vals[i]]+p[b-vals[i]] == 0){
            cout << "NO" << endl;
            return;
        }
    }
    
    rep(i, 0, n){
        if(p[a-vals[i]]+p[b-vals[i]] == 1){
            if(p[a-vals[i]] == 1) dfs(vals[i], 0);
            else dfs(vals[i], 1);
            
        } 
    }

    rep(i, 0, n){
        if(ans[vals[i]] == 0){
            if(p[a-vals[i]] == 0){
                cout << "NO" << endl;
                return;
            }
        }
        if(ans[vals[i]] == 1){
            if(p[b-vals[i]] == 0){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

    rep(i, 0, n){
        cout << ans[vals[i]] << ' ';
    }
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}