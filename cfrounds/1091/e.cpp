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
    vector<int> p(n); rep(i,0 ,n) cin >> p[i];
    vector<int> d(n); rep(i, 0, n) cin >> d[i];
    vector<int> q(n);
    int big = 2*n;
    for(int i = n-1; i>=0; i--){
        int pdom = 0;
        vector<pair<int, int>> dom;
        rep(j, i+1, n){
            if(p[j] > p[i]){
                pdom++;
                dom.push_back({q[j], j});
            }
        } 
        if(d[i] > pdom){
            cout << -1 << endl;
            return;
        }

        
        int qi = big;
        big++;
        sort(all(dom), greater<pair<int, int>>());
        if(d[i] > 0){
            qi = dom[d[i]-1].first;
        }
        rep(j, i+1, n) if(q[j] >= qi) q[j]++;
        q[i] = qi;
    }
    vector<pair<int, int>> qgod(n);
    rep(i, 0, n) qgod[i] = {q[i], i};
    sort(all(qgod));
    rep(i, 0, n) q[qgod[i].second] = i+1;
    rep(i, 0, n) cout << q[i] << ' ';
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}