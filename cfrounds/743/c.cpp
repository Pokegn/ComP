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
    int n; cin >> n;
    vector<vector<int>> a(n+1); //los que necesitan al weon i

    
    vector<bool> vis(n+1, false);
    vector<vector<int>> ans(n+1);
    rep(i, 1, n+1){
        int k; cin >> k;
        if(k == 0) ans[0].push_back(i);
        rep(j, 0, k){
            int xd; cin >> xd;
            a[xd].push_back(i);
        } 
    }

    for(auto xd: a) sort(all(xd));
    
    vector<int> need(n+1, 0);
    rep(i, 1, n+1){
        need[i] = a[i].size();
    }


    rep(i, 0, n){
        for(auto curr: ans[i]){//curr es un weon que puedo leer despues de i leidas
            if(vis[curr]) continue;
            vis[curr] = true;

            for(auto j: a[curr]){//los que necesitan a curr
                need[j]--;
                if(need[j] == 0){

                }
            }
        }
    }


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}