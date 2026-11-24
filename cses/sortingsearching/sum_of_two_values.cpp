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
    int n,x; cin >> n >> x;
    vector<pii> a(n); rep(i,0 ,n) cin >> a[i].fi;
    rep(i,0,n) a[i].se = i;

    sort(all(a));
    int l = 0, r = n-1;
    while(l < r){
        int sum = a[l].fi + a[r].fi;
        if(sum == x){
            cout << a[l].se+1 << ' ' << a[r].se+1 << endl;
            return;
        }
        if(sum < x) l++;
        if(sum > x) r--;
    }
    cout << "IMPOSSIBLE" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}