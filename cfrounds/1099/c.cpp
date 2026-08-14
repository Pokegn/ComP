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

int op(int xd){
    if(xd%2 == 0){
        return xd/2;
    }
    return xd+1;
}

void solve(){
    int n; cin >> n; 
    vi a(n); rep(i, 0, n) cin >> a[i];
    int ans = 0;
    bool flag = false;
    while(!flag){
        sort(all(a));
        //for(auto k : a) cout << k << ' '; cout << endl;
        if((a[n-1]+1)/2 == (a[0]+1)/2){
            flag = true;
            break;
        }
        rep(i, 0, n){
            while((int)((a[i]+1)/2) > ((a[0]+1)/2)){
                a[i] = op(a[i]);
                ans++;
            }
        }
    }
    int odd = 0, even = 0;
    //cout << "prelim " << ans << endl;
    rep(i, 0, n){
        if(a[i]%2 == 1) odd++;
        else even++;
    }
    if((a[0]+1)/2 == 1){
        ans += min(even, odd);
    }
    else{
        if(even > 0) ans += odd;
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