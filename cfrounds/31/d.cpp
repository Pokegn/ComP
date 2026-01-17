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
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n; cin >> n;
    vlli a(n); for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) a[i]*=2;

    ll ans = 0;
    ll curr = 0;
    ll cadenas = 0;
    ll start = 0;
    while(curr<n){
        ll maxreach;
        ll reach, rad;

        start = curr;
        cadenas++;
        ll l = 1, r = 1e9;
        if(curr>0) r = a[curr] - a[curr-1] - 1;
        ll m;
        while(r-l>1){
            m = (l+r)/2;
            rad = m;
            reach = curr;
            
            while(reach<n-1 && a[reach+1]-a[reach] < rad){
                reach++;
                rad = rad-(a[reach+1]-a[reach]);
            }
            if(reach == n-1){
                curr = n;
                break;
            }
            if(reach%2 == curr%2){
                r = m;
            }
            else l = m;
        }

        if(curr == n) break;

        rad = l;
        reach = curr;
        while(reach<n-1 && a[reach+1]-a[reach] < rad){
            reach++;
            rad = rad-(a[reach+1]-a[reach]);
        }
        if(reach == n-1){
            curr = n;
        }

        maxreach = reach;

        rad = r;
        reach = curr;
        while(reach<n-1 && a[reach+1]-a[reach] < rad){
            reach++;
            rad = rad-(a[reach+1]-a[reach]);
        }
        if(reach == n-1){
            curr = n;
        }

        maxreach = max(maxreach, reach);
        if(curr!=n) curr = maxreach+1;
    }
    cout << n-1-cadenas << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}