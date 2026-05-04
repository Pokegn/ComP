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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;

    vector<vector<string>> tops(n, vector<string>(10));
    set<string> artists;
    map<string, vector<int>> m;
    map<string, int> app;
    int maxapp = -1;
    rep(i, 0, n){
        rep(j, 0, 10){
            cin >> tops[i][j];
            string sss = tops[i][j];
            app[sss]++;
            maxapp = max(maxapp, app[sss]);
            artists.insert(tops[i][j]);
            if(m[sss].size() == 0) m[sss] = vector<int>(10, 0);
            m[sss][j]++;
        }
    }

    vector<vector<int>> god;
    for(auto art: artists){
        if(app[art] == maxapp)
        god.push_back(m[art]);
    } 
    sort(all(god));

    int sz = god.size();
    auto obj = god[sz-1];
    string ans = "";
    for(auto art: artists){
        if(obj == m[art]){
            if(ans!=""){
                cout << "tie" << endl;
                return;
            }
            else{
                ans = art;
            }
        }
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}