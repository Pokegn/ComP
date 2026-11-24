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
    int n,m; cin >> n>>m;
    vector<ll> a(n); rep(i,0,n) cin >> a[i];
    vector<ll> pos(n);
    rep(i,0,n) pos[a[i]-1] = i; //en que posicion esta a[i]
    
    int ans = 1;
    rep(i, 1, n) if(pos[i] < pos[i-1]) ans++;

    // rep(i,0,n) cout << pos[i] << ' '; cout << endl;
    rep(i,0,m){
        int x,y; cin >> x >> y; x--,y--;

        int valx = a[x]-1, valy = a[y]-1;
        int antes = 0;
        int despues = 0;
        if(valx > 0 && pos[valx] < pos[valx-1]) antes++;
        if(valx < n-1 && pos[valx+1] < pos[valx]) antes++;
        if(valy-1 != valx && valy > 0 && pos[valy] < pos[valy-1]) antes++;
        if(valy+1 != valx && valy < n-1 && pos[valy+1] < pos[valy]) antes++;
        swap(pos[valx], pos[valy]);
        swap(a[x], a[y]);
        if(valx > 0 && pos[valx] < pos[valx-1]) despues++;
        if(valx < n-1 && pos[valx+1] < pos[valx]) despues++;
        if(valy-1 != valx && valy > 0 && pos[valy] < pos[valy-1]) despues++;
        if(valy+1 != valx && valy < n-1 && pos[valy+1] < pos[valy]) despues++;
        // rep(i,0,n) cout << pos[i] << ' ';
        // cout << ' ';
        ans += despues-antes;
        // cout << valx << ' ' << valy << ' ' << antes << ' ' << despues << ' ';
        cout << ans << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}