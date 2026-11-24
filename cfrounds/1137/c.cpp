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
    vi a(n); rep(i,0,n) cin >> a[i];
    if(n == 1){
        cout << 1 << endl;
        return;
    }

    ll ans = n;

    // int l = a[0];
    // int howmany = 1;
    // while(howmany < n && a[howmany] > l) howmany++;
    // ans += howmany-1;
    
    // int r = a[n-1];
    // howmany = 1;
    // while(howmany < n && a[n-1-howmany] > r) howmany++;
    // ans += howmany-1;

    vi index(n);
    rep(i,0,n){
        index[a[i]-1] = i; //indexado en 0
    }

    set<int> idx;  //indices que tengo
    set<int> negidx;
    vi der(n), izq(n); //indices
    idx.insert(n);
    negidx.insert(1);
    rep(i,0,n){
        der[i] = *idx.upper_bound(index[i]);
        izq[i] = -(*negidx.upper_bound(-index[i]));
        // cout << i << ' ' << ans << endl;
        idx.insert(index[i]);
        negidx.insert(-index[i]);
        // if(index[i] == 0){
        //     continue;
        // }
        // if(a[index[i]-1] > a[index[i]]) continue;
        // // cout << "llegue a " << i+1 << endl;
        // auto it = idx.upper_bound(index[i]);
        // if(it == idx.end()){
        //     ans += n - index[i] - 1;
        // }
        // else{
            
        //     ans += (*it)-index[i]-1;
        // }
    }

    rep(i,0,n){
        if(izq[i] == index[i]-1){
            ans += der[i]-index[i]-1;
            continue;
        }
        if(der[i] == index[i]+1){
            ans += index[i]-izq[i]-1;
            continue;
        }
        ans++;
    }
    cout << ans << endl;

    // cout << ans << endl;
    // return;

    // rep(i,1,n-1){
    //     int left = 0, right = 0;
    //     left = a[i-1];
    //     right = a[i+1];
    //     if(a[i] < left){
    //         ans++;
    //     } 
    // }

    // cout << ans<< endl;
    // return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}