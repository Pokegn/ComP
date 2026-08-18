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
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> ranges;
    rep(i, 0, n){
        ll l, r; cin >> l >> r;
        if(r-l >= k){
            ranges.push_back({0, k-1});
            continue;
        }
        l%=k;
        r%=k;
        if(r>=l){
            ranges.push_back({l, r});
        }
        else{
            ranges.push_back({l, k-1});
            ranges.push_back({0, r});
        }
    } 

    set<ll> rangevals;
    for (auto r: ranges){
        rangevals.insert(r.fi);
        rangevals.insert(r.se);
    }

    vector<ll> vals;
    for(auto x: rangevals) vals.push_back(x);

    sort(all(vals));

    vector<ll> count(vals.size()+1, 0);
    rep(i, 0, ranges.size()){
        ll l = ranges[i].fi;
        ll r = ranges[i].se;
        int i1, i2;
        auto it = lower_bound(all(vals), l);
        if(it == vals.end()) continue;
        i1 = (int)(it - vals.begin());
        it = upper_bound(all(vals), r);
        if(it == vals.end()){
            i2 = vals.size()-1;
        }
        else{
            i2 = (int)(it - vals.begin()) - 1;
        }
        count[i1]++;
        count[i2+1]--;
    }
    int curr = 0;
    int ans = 0;
    rep(i, 0, vals.size()+1){
        curr += count[i];
        ans = max(ans, curr);
        // cout << i <<' ' << curr << endl;
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}