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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, q; cin >> n >> q;
    vector<vector<pair<lli, lli>>> grafo(n, vector<pair<lli, lli>>(0));

    lli u,v,w;
    forn(i, 0, n-1){
        cin >> u >> v >> w;
        grafo[u-1].pb({v-1,w});
        grafo[v-1].pb({u-1,w});
    }
    forn(i, 0, n){
        sort(grafo[i].begin(), grafo[i].end(), [](auto a, auto b){
            return a.second > b.second;
        });
    }


    vector<pair<lli ,lli>> rango(n, {1000000000000, 1000000000000});
    rango[0] = {0, 1000000000000};
    vector<bool> bfs_vis(n, false);
	queue<int> bfs; bfs.push(0); bfs_vis[0] = true;
    lli hijo;

	while(!bfs.empty()) {
		int bfssz = bfs.size();
		while(bfssz--) {
			int u = bfs.front();
			bfs.pop();

			for(pair<lli, lli> v : grafo[u]){
                hijo = v.first;
				if(!bfs_vis[hijo]){
					bfs.push(hijo);
					bfs_vis[hijo] = true;

                    if(v.second > rango[u].second || rango[u].first >= rango[u].second){
                        rango[hijo].first = 1000000000000;
                        rango[hijo].second = 1000000000000;
                    }
                    else{
                        rango[hijo].second = rango[u].second;
                        rango[hijo].first = max(v.second, rango[u].first);
                        rango[u].second = min(rango[u].second, rango[hijo].first);
                    }
                    
				}
			}
		}
	}

    vvlli rangoconindice(n, vlli(3));
    forn(i, 0, n){
        rangoconindice[i][0] = i;
        rangoconindice[i][1] = rango[i].first;
        rangoconindice[i][2] = rango[i].second;
    }
    sort(rangoconindice.begin(), rangoconindice.end(), [](auto a, auto b){
        return a[1] < b[1];
    });

    vlli x(q); forn(i, 0, q) cin >> x[i];
    sort(x.begin(), x.end());
    // forn(i, 0, n){
    //     cout << rangoconindice[i][0] << ' ' << rangoconindice[i][1] << ' ' << rangoconindice[i][2] << nl;
    // }

    // forn(i, 0, n){
    //     if(rangoconindice[i][1] >= rangoconindice[i][2]){
    //         while(true) cout << "xd";
    //     }
    // }

    lli ans = 0;
    lli i =0, j=0; //i es el indice en las x[i]'s y j en rangoconindice
    while(i<q){
        
        if(rangoconindice[j][2] >= x[i]){
            ans+=rangoconindice[j][0]+1;
            //cout << rangoconindice[j][0]+1;
            i++;
        }
        else j++;
    }

    cout << ans << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}