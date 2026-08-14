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

void solve(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    int signo = 1;
    vector<int> movs;

    ll lastpos = -1;
    rep(i, 0, n){
        if(a[i] > 0) lastpos = i;
    }

    //agarro el doble de la suma de los negativos sum
    //y quiero el positivo tal que sum - x se maximice
    int idx = -1;
    ll sum = 0;
    ll val = 0;
    rep(i, 0, n){
        if(a[i] < 0) sum -= 2*a[i];
        if(a[i] > 0){
            if(sum - 2*a[i] > val){
                val = sum - 2*a[i];
                idx = i;
            }
        }
    }
    if(idx == -1){
        cout << 0 << endl;
        cout << endl;
        return;
    }

    for(int i = idx-1; i>=0; i--){
        if(a[i]*signo > 0){
            movs.push_back(i+1);
            signo*=-1;
        }
    }
    movs.push_back(idx+1);

    cout << movs.size() << endl;
    for(int i = 0; i < movs.size(); i++) cout << movs[i] << ' ';
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}