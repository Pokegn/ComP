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
    vi a(n); rep(i,0,n) cin >> a[i];
    vi b = a;
    vector<bool> change(n, false);
    int maxi = a[0];
    int mink = 0;
    int l = 0, r = 1000000000;
    rep(i, 1, n){
        if(a[i] < maxi){
            mink = max(mink, maxi - a[i]);
            a[i] = a[i] + max(mink, maxi-a[i]);
            change[i] = true;
        }
        maxi = max(a[i], maxi);
    }

    rep(i, 1, n){
        if(b[i] < b[i-1]) b[i] += mink;
    }

    rep(i,1 , n){
        if(b[i] < b[i-1]){
            cout << "NO" << endl;
            return;
        } 
    }


    cout << "YES" << endl;
    return;

    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}