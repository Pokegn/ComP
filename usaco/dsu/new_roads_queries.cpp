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

const int MAXN = 1e6+1;
vector<int> lst[MAXN];
int parent[MAXN];
vector<vector<pii>> partof(MAXN);
int t;

void make_set(int v){
    lst[v] = {v};
    parent[v] = v;
}

int find_set(int v){
    return parent[v];
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(lst[a].size() < lst[b].size()) swap(a,b);
        while(!lst[b].empty()){
            int x = lst[b].back();
            lst[b].pop_back();
            lst[a].push_back(x);
            parent[x] = a;
            partof[x].push_back({t, a});
        }
    }
}

void solve(){
    int n,m,q; cin >> n >> m >> q;
    rep(i, 0, n){
        make_set(i);
        partof[i].push_back({0, i});
    }
    t = 0;
    rep(i, 0, m){
        t++;
        int u,v; cin >> u >> v; u--; v--;
        union_sets(u,v);
    }

    // rep(i, 0, n){
    //     cout << i << ": \n";
    //     for(auto p: partof[i]){
    //         cout << p.fi << ' ' << p.se << endl;
    //     }
    // }

    rep(i, 0, n) sort(all(partof[i]));

    while(q--){
        int u,v; cin >> u >> v; u--; v--;
        int l = 0, r = m+1;
        while(l < r){
            int mid = (l+r)/2;
            //checo si en m dias ya estan
            pii PENE = {mid, 1000000};
            auto it1 = upper_bound(all(partof[u]), PENE)-1;
            auto it2 = upper_bound(all(partof[v]), PENE)-1; 
            if((*it1).se == (*it2).se){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        if(l == m+1) cout << -1 << endl; 
        else
        cout << l << endl;
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int tt=1; 
    //cin >> t;
    while(tt--) solve();
    return 0;
}