#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
//#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n, k; cin >> n >> k;
    ll l = 1, r = n;
    string re; 
    while(true){
        if(r - l + 1 > 45){
            cout << l << ' ' << (l+r)/2 << endl;
            cin >> re;
            if(re == "Yes"){
                r = min(n, (l+r)/2+k);
                continue;
            }
            else{
                l = max(1ll, (l+r)/2+1-k);
                continue;
            }
        }
        else{
            ll rango = (r-l+1);
            ll random = rand()%rango;
            cout << l+random << ' ' <<l+random << endl;
            cin >> re;
            if(re == "Yes"){
                return;
            }
            else{
                l = max(l-k, 1ll);
                r = min(r+k, n);
                continue;
            }

        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}