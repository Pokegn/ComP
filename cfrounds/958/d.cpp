#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void bfs(){

}

void solve(){
    lli n; cin >> n;
    vlli a(n+1);
    forn(i, 1, n+1) cin >> a[i];
    vvlli grafo(n+1);
    lli u,v;
    forn(i, 0, n-1){
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vector<pair<lli, lli>> score(n+1, {0,0});
    forn(i, 1, n+1){
        score[i].first = a[i];
        for(auto uu: grafo[i]) score[i].first-=uu;
        score[i].second = i;
    }

    lli tomados = 0;
    lli ans = 0;
    vector<bool> cancel(n+1, 0);
    lli ronda = 1;
    while(tomados < n){
        cancel = vector<bool> (n+1, 0);
        sort(score.begin(), score.end(), greater<pair<lli, lli>>());
        forn(i, 0, n){
            ans+=score[i].first;
            auto x = score[i].first;
            auto y = score[i].second;
            if(cancel[y] == true || score[i].first == 0) continue;
            score[i].first = 0;
            tomados++;
            for(auto j: grafo[y]) cancel[j] = true;
        }
    }
    cout << ans << nl;

    queue<lli> bfs; bfs.push(1);
    vector<bool> bfs_vis(n+1, false); bfs_vis[1] = true;
    while(!bfs.empty()){
        lli bfssz = bfs.size();
        while(bfssz--){
            int u = bfs.front();
			bfs.pop();

			for(int v : grafo[u])
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
				}
        }
    }

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}