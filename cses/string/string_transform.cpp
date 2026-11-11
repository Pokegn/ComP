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
    string s; cin >> s;
    int n = sz(s);

    vi a(n); rep(i, 0, n) a[i] = (int)(s[i]);
    
    vector<pii> xd;
    rep(i, 0, n){
        xd.push_back({a[i], i});
    }

    sort(all(xd));
    vi go(n);
    rep(i, 0, n){
        int idx = xd[i].se;
        go[i] = idx;
    }

    int curr = -1;
    rep(i, 0, n) if(i == xd[0].se) curr = i;

    rep(i, 0, n-1){
        cout << (char)xd[curr].fi;
        curr = go[curr];
    }
    
    cout << endl;
    return;
    
}

//cb#ab
//#abbc

//ans es babc#
//01234
//23140

//entonces mando


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}