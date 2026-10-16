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
    ll n; cin >> n;
    vector<ll> ans(0);
    vi currloc;
    currloc = {0, 1, 2};

    //ORDEN
    vi orden;
    orden = {0, 1, 2};

                        ll mod = orden[0]; //asumiendo que empezo en 0

    ll finale = ((2*n)/3)*3 + mod;
    if(finale > 2*n) finale -= 3;

    ll mov = finale;
    while(mov >= 2){
        ans.push_back(mov);
        mov-=2;
        rep(i, 0, 3) currloc[i] = (currloc[i]+1)%3;
    }

                        mod = (orden[1]+currloc[1])%3; //asumiendo que empezo en 0

    finale = ((2*n)/3)*3 + mod;
    if(finale > 2*n) finale -= 3;

    mov = finale;
    while(mov >= 2){
        ans.push_back(mov);
        mov-=2;
        rep(i, 0, 3) currloc[i] = (currloc[i]+1)%3;
    }


                        mod = (orden[2]+currloc[2])%3; //asumiendo que empezo en 0

    finale = ((2*n)/3)*3 + mod;
    if(finale > 2*n) finale -= 3;

    mov = finale;
    while(mov >= 2){
        ans.push_back(mov);
        mov-=2;
    }
    // cout << 3*n << ' ';
    cout << sz(ans) << endl;
    for(auto x: ans) cout << x << ' ';
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}