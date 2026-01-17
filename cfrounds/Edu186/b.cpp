#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll a,b; cin >> a >> b;
    if(b>a) swap(a,b);
    ll ans = 0;
    vlli many(30);
    many[1] = 1;
    many[0] = 0;
    many[2] = 2;
    ll pot = 4;
    for(int i=3; i<30; i++){
        many[i] = many[i-2] + pot;
        pot*=2;
    }

    for(int i=1; i<30; i++){
        if(a >= many[i] && b >= many[i-1]){
            ans = i;
        }
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}