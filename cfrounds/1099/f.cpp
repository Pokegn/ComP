#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
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

vector<vector<ll>> g;
ll n;

int ans(ll a, ll b){
    vector<ll> occurrences(n+1, 0);
        for(auto v: g[a]) occurrences[v]++;
        for(auto v: g[b]) occurrences[v]++;
        if(occurrences[a] >= 1 || occurrences[b] >= 1){
            return 1;
        }
        else{
            bool flag = false;
            rep(i, 1, n+1){
                if((flag == false) && (occurrences[i] >= 2)){
                    return 2;
                    flag = true;
                }
            }
            if(flag == false) return 3;
        }
}

void solve(){
    ll q; cin >> n >> q;
     g = vector<vector<ll>>(n+1);
    rep(i, 1, n+1){
        for(ll sq = 1; sq*sq <= n; sq++){
            if((i + sq*sq) <= n){
                g[i].push_back(i+sq*sq);
                g[i+sq*sq].push_back(i);
            }
        }
    }

    while(q--){
        ll a,b; cin >> a >> b;
        cout <<ans(a,b) << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}