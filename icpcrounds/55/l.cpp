//https://codeforces.com/group/GHvtTrfZFd/contest/706597/problem/L

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

void solve(){
    int n; cin >> n;
    vector<string> sign(n);
    vi a(n); rep(i, 0, n) cin >> sign[i] >> a[i];

    map<int, int> enter;
    vector<pair<int, int>> events;

    rep(i, 0, n) enter[a[i]] = 0;

    rep(i, 0, n){
        if(sign[i] == "-"){
            if(enter[a[i]] == 0) events.push_back({0, 1});
            enter[a[i]] = 1;
            events.push_back({i+1, -1});
        } 
        else{
            enter[a[i]] = 1;
            events.push_back({i+1, 1});
        } 
    }

    sort(all(events));

    int ppl = 0;
    int ans = 0;

    for(auto p: events){
        //cout << p.first << ' ' << p.second << endl;
        ppl += p.second;
        ans = max(ppl, ans);
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