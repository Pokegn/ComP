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
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<int> untilget(n+1, 0);
    rep(i, 0, n){
        if(b[i] != 0) untilget[b[i]] = i+1;
    }

    bool formados = true;
    int idx = 0;
    while(idx < n && b[idx] != 1) idx++;
    if(idx == n) formados = false;

    rep(i, idx+1, n){
        if(b[i]-b[idx] != i-idx) formados = false;
    }

    // if(!formados) cout << "XD ";
    // if(formados) cout << "roge dictador ";

    if(formados){
        int lastformado = b[n-1];
        bool tite = false;
        rep(i, lastformado+1, n+1){
            if(untilget[i] >= i-lastformado) tite = true;
        }
        if(!tite){
            cout << n - lastformado << endl;
            return;
        }
    }

    int whenListo = 0;
    rep(i, 1, n+1){
        whenListo = max(whenListo, untilget[i]+1-i);
    }
    cout << whenListo + n << endl;
    return;


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}