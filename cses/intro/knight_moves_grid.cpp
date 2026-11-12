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
typedef vector<vi> vvi;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vvi a;
int n;
vector<pii> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void solve(){
    cin >> n;
    a.assign(n, vi(n, -1));

    queue<pii> bfs; bfs.push({0,0});
    a[0][0] = 0;
    int val = 1;
    while(!bfs.empty()){
        int bfssz = bfs.size();
        while(bfssz--){
            auto u = bfs.front();
            bfs.pop();

            for(auto x: moves){
                pii v = {u.fi + x.fi, u.se+x.se};
                if(v.fi < 0 || v.fi > n-1) continue;
                if(v.se < 0 || v.se > n-1) continue;
                if(a[v.fi][v.se] != -1) continue;
                a[v.fi][v.se] = val;
                bfs.push(v);
            }
        }
        val++;
    }

    rep(i, 0,n){
        rep(j, 0, n) cout << a[i][j] << ' ';
        cout << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}