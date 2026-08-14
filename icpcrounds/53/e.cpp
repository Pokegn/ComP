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

vector<vector<ll>> mat;
map<ll, pair<ll, ll>> ans;

bool possible(ll val){
    ll n = mat.size();
    ll m = mat[0].size();
    
    vector<pair<ll, ll>> xd;
    ll temp;
    map<ll, ll> mapa;
    for(int j = 0; j < n; j++){
        auto vec = mat[j];
        temp = 0;
        for(int i = 0; i < m; i++){
            if(vec[i] >= val){
                temp += 1<<i;
            }
        }
        if(mapa[temp] == 1) continue;
        mapa[temp] = 1;
        xd.push_back({temp, j});
    } 

    for(auto x: xd){
        for(auto y: xd){
            if((x.first|y.first) == (1<<m)-1){
                ans[val] = {x.second, y.second};
                return true;
            }
        }
    }
    return false;
    
}

void solve(){
    ll n, m; cin >> n >> m;

    mat = vector<vector<ll>> (n, vector<ll>(m));
    rep(i, 0, n){
        rep(j, 0,m){
            cin >> mat[i][j];
        }
    }

    ll l = 0, r = 1000000000;
    while(l < r){
        ll mid = (l+r+1)/2;
        if(possible(mid)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans[l].first+1 << ' ' << ans[l].second+1 << endl; return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}