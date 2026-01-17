#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n; cin >> n;
    vlli x(n); for(int i=0; i<n; i++) cin >> x[i];

    sort(x.begin(), x.end());
    ll a,b,c;
    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            a = x[i], b= x[j];
            c = x[0];
            ans = max(ans, a*a+b*b+c*c-a*b-b*c-c*a);
            c = x[n-1];
            ans = max(ans, a*a+b*b+c*c-a*b-b*c-c*a);
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}