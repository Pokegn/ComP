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

void solve(){
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    vvlli grafo(26, vlli(0));
    lli s1sz = s1.length();
    lli s2sz = s2.length();
    lli s3sz = s3.length();

    if(s1sz != s2sz){
        cout << "NO" << nl;
        return;
    }

    if(s1sz != s3sz){
        cout << "YES" << nl;
        return;
    }

    forn(i, 0, s1sz){
        if(i>=s2sz) continue;
        grafo[s1[i]-'a'].push_back(s2[i]-'a');
        grafo[s2[i]-'a'].push_back(s1[i]-'a');
    }

    queue<int> bfs;
    vector<bool> bfs_vis(26, false);
    vector<char> f(26);

    forn(i, 0, 26){
        if(bfs_vis[i]) continue;
	    bfs = queue<int>();
        bfs.push(i); bfs_vis[i] = true;

        f[i] = 'a'+i;

	    while(!bfs.empty()) {
            int bfssz = bfs.size();
            while(bfssz--) {
                int u = bfs.front();
                bfs.pop();

                for(int v : grafo[u]){
                    if(!bfs_vis[v]) {
                        f[v] = f[u];
                        bfs.push(v);
                        bfs_vis[v] = true;
                    }
                }
            }
        }
    }

    forn(i, 0, s1sz){
        if(f[s1[i]-'a'] != f[s3[i]-'a']){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
    return;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    lli t; cin >> t;
    while(t--)
    solve();
    return 0;
}