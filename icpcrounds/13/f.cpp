#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n; cin >> n;
    vlli a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    bool increasing = true;
    ll ind = -1;
    for(int i=1; i<n; i++){
        if(a[i]<= a[i-1]){
            increasing = false;
            ind = i-1;
        }
    }

    if(increasing == false){
        ll row = a[ind+1]-1;
        ll c = a[ind]/row;
        cout << c << endl;
    }
    else{
        ll g = __gcd(a[0], a[1]);
        ll r = a[n-1]/g;
        cout << max(g, r) << endl;
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}