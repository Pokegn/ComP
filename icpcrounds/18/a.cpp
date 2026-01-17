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
    ll n; cin>> n;
    bool xd = true;
    for(int i=0; i<n; i++){
        vlli a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if(a[0]+a[1]<=a[2]){
            xd = false;
            
        }
    }
    if(!xd){
        cout << "NO" << endl;
        return;
    }
    cout <<"YES" <<endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}