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
    ll x,y; cin >> y >> x;
    ll ans = 0;
    if(x>y){
        if(x%2 == 1){
            ans = x*x;
            ans -= y-1;
            cout << ans << endl;
            return;
        }
        else{
            ans = (x-1)*(x-1);
            ans+=y;
            cout << ans << endl;
            return;
        }
    }
    else{
        if(y%2 == 0){
            ans = y*y;
            ans -= x-1;
            cout << ans << endl;
            return;
        }
        else{
            ans = (y-1)*(y-1);
            ans+=x;
            cout << ans << endl;
            return;
        }

    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}