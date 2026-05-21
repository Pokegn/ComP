#include <bits/stdc++.h>
 
using namespace std;

vector<int> ans;
vector<vector<int>> grafo;
vector<bool> vis;
vector<long long> dp;
vector<bool> final_vis;

void cocon(long long u){
    long long ans=0;
    vis[u]= 1;

    for(int v: grafo[u]){
        if(!vis[v]){
            cocon(v);
            ans+=dp[v]+1;
        }
    }
    dp[u] = ans;
    return;
}


void solve(){
    int n; cin >> n;
    int a,b;
    grafo.assign(n+1, {});
    ans.assign(n+1, 0);
    vis.assign(n+1, 0);
    final_vis.assign(n+1, 0);
    dp.assign(n+1, 0);

    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);

    }

    cocon(1);
    int u = 1;
    int mequieromatar;

    while(2 == 5/2){
        mequieromatar = 0;
        final_vis[u] = 1;

        for(int v: grafo[u]){

            if(final_vis[v] == 1) continue;

            if(dp[v]+1 > n/2){
                u = v;
                mequieromatar = 1;
                break;
            }

        }

        if(mequieromatar == 0) break;
    
    }
    
    cout << u << '\n';
    
    return;


}
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();

    return 0;
}