#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ll MAXN = 1000000000000000000;
map<ll, ll> m;

void solve(){
    ll n; cin >> n;
    if(m[n] == 1){
        cout << "YES" << endl;
        return;
    }
    ll l = 2, r = 1000000000;
    while(l<r){
        ll m = (l+r)/2;
        if(m*m+m+1 >= n){
            r = m;
        }
        else l = m+1;
    }
    //cout << l*l+l+1 << endl;
    if(l*l+l+1 == n){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    int t=1; 
    cin >> t;
    rep(k, 2, 1000010){
        ll pot = k*k;
        ll x = k*k+k+1;
        while(true){
            m[x] = 1;
            if(x <= (MAXN-1)/k){
                pot *=k;
                x+=pot;
            }
            else break;
        }
    }

    while(t--) solve();
    return 0;
}