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
    int n, k; cin >> n >> k;
    vector<int> a(n+1, 0);
    vector<int> p(k); rep(i, 0, k) cin >> p[i];
    rep(i, 1, n+1){
        bool lose = true;
        rep(j, 0, k){
            if(i - p[j] >= 0 && a[i-p[j]] == 0) lose = false;
        }
        if(!lose) a[i] = 1;
    }

    rep(i, 1,n+1){
        if(a[i] == 1) cout << 'W';
        else cout << 'L';
    }
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}