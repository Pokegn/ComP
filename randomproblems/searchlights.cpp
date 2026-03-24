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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(m);

    rep(i, 0, n){
        cin >> a[i].first >> a[i].second;
    }
    rep(i, 0, m){
        cin >>b[i].first >> b[i].second;
    }
    
    vector<pair<int, int>> reach;
    rep(i, 0, n){
        rep(j, 0, m){
            reach.push_back({(b[j].first >= a[i].first ? b[j].first-a[i].first+1 : 0),
                 (b[j].second >= a[i].second ? b[j].second-a[i].second+1 : 0)});
        }
    }
    
    //quiero, para cada i, quiero el mayor valor de y entre los weones con x>i
    // cout << "reach" << endl;
    // for(auto p:reach) cout << p.first << ' '<< p.second << endl;
    // cout << endl;

    vector<int> maxy(1000003, 0);
    maxy[1000002] = 0;
    for(auto p: reach){
        if(p.first == 0) continue;
        maxy[p.first-1] = max(maxy[p.first-1], p.second); //
    }
    for(int i = 1000001; i>=0; i--){
        maxy[i] = max(maxy[i+1], maxy[i]);
    }

    int ans = 2000002;
    rep(i, 0, 1000002){
        ans = min(ans, i+maxy[i]);
    }

    // rep(i, 0, 20){
    //     cout << i << ' ' << maxy[i] << endl;
    // }

    cout << ans << endl;
    return;










    // sort(all(reach), greater<pair<int, int>>());

    // int maxy = 0;
    // int ans = INT32_MAX;
    // //vector<pair<int, int>> losgod;
    // for(auto p:reach){
    //     if(p.second >= maxy){
    //         //losgod.push_back(p);
    //         ans = min(p.first + p.second, ans);
    //         maxy = p.second;
    //     }
    // }

    // cout << ans << endl;
    // return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}