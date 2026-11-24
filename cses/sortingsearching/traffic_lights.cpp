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
    ll x; cin >> x;
    int n; cin >>n;
    vector<ll> a(n); rep(i,0,n) cin >> a[i];
    rep(i,0,n) a[i]*=-1;
    set<ll> lights;
    lights.insert(0);
    lights.insert(-x);

    multiset<ll> distances;
    distances.insert(-x);

    rep(i,0,n){
        auto it = lights.upper_bound(a[i]);
        ll next = *it;
        ll prev = *(--it);

        ll dist = -next+prev;
        distances.erase(distances.find(dist));
        distances.insert(-next + a[i]);
        distances.insert(-a[i] + prev);

        lights.insert(a[i]);


        cout << -*distances.begin() << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}