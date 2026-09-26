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

map<ll, ll> fin;

ll cambia(ll n){
    ll suma = 0;
    ll orig = n;
    while(n>0){
        suma += (n%10)*(n%10);
        n/=10;
    }
    return suma;
    // cout << suma << ' ' << orig << endl;
    // if(suma == orig) return suma;
    // return cambia(suma);
}

void solve(){
    vector<ll> tiene(1000, 0);
    ll n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    rep(i, 0, n){
        rep(j, 0, 67) a[i] = cambia(a[i]);
        // cout << a[i] << ' ';
        tiene[a[i]]++;
    }
    // cout << endl;
    ll ans = 0;
    rep(i, 0, 1000){
        ans += tiene[i]*(tiene[i]-1);
    }
    ans/=2;
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    cin >> t;

    // rep(i, 0, 1000){
    //     fin[i] = cambia(i);
    // }

    while(t--) solve();
    return 0;
}