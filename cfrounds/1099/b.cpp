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
    vector<bool> change(n, false);
    vector<vi> escaleras = {{a[0]}};
    int maxi = a[0];
    int l = 0, r = 1000000000;
    rep(i, 1, n){
        if(a[i] < maxi){
            l = max(l, maxi - a[i]);
            change[i] = true;
            escaleras.push_back({a[i]});
            //a[i] = a[i-1];
        }
        else{
            escaleras.back().push_back(a[i]);
        }
    }

    // for(auto arr: escaleras){
    //     cout << arr.size() << ' ';
    //     for(auto x: arr){
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }

    rep(i, 1, escaleras.size()){
        int currmax = 0;
        rep(j, 1, escaleras[i].size()){
            currmax = max(currmax, escaleras[i][j] - escaleras[i][j-1]);
        }
        if(i == escaleras.size()-1) currmax = 1000000000;
        else currmax = max(currmax, escaleras[i+1][0] - escaleras[i][escaleras[i].size()-1]);
        r = min(r, currmax);
    }
    
    cout << "l r" << ' ' << l << ' ' << r << endl;
    if(l <=r ){
        cout << "YES" << endl;
                return;

    }
    else{
        cout << "NO" << endl;
        return;
    }

    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}