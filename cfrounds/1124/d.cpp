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

ll countdif(ll n){
    ll imp = 0, par = 0;
    while(n > 0){
        imp+=n%2;
        n/=2;
        par+=n%2;
        n/=2;
    }
    if(imp%2 == par%2){
        return 0;
    } 
    return 1;
}

void solve(){
    ll n, q; cin >> n >> q;

    // rep(i, 0, 16) cout << i << ' ' << countdif(ll(i)) << endl;

    vector<ll> a(n); rep(i, 0, n) cin >> a[i];

    ll dif = 0;
    ll canwin = 0;
    rep(i, 0, n){   
        dif = countdif(a[i]);
        if(dif == 0){
            canwin++;
        }
    } 
    cout << canwin << ' ';

    rep(i, 0, q){
        ll idx, x; cin >> idx >> x;
        if(countdif(a[idx-1]) == 0) canwin--;
        if(countdif(x) == 0) canwin++;
        a[idx-1] = x;
        cout << canwin << ' ';
    }
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}