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
typedef vector<long long> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n ; cin >> n;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    map<pair<ll, ll>, int> m;
    int ans = 0;
    int comodin = 0;
    rep(i, 0, n){
        if(a[i] == 0){
            if(b[i] == 0) comodin++;
        }
        else{
            pair<ll, ll> p = {-b[i], a[i]};
            ll g = __gcd(-b[i], a[i]);
            p.first /=g;
            p.second /= g;
            if(p.second < 0){
                p.first *=-1;
                p.second *=-1;
            }
            m[p]++;
            ans = max(m[p], ans);
        }
    }
    cout << ans + comodin << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}