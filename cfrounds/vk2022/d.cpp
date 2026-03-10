#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ll y(ll a, ll b){
    if((a+b)%2 != 0) return -1;
    if(b>a) swap(a,b); // a>=b
    ll y = a+b; y/=2;
    // ll z = a-b; z/=2;
    return y; // regresa y>z
}

void getx(vector<ll> &x, ll a1, ll a2){ //a1 < a2
    ll dif = a2-a1;
    for(ll i = 1; i*i <=dif; i++){
        if(dif%i == 0){
            ll yy = y(i, dif/i);
            if(yy != -1 && yy*yy - a2 >= 0) x.push_back(yy*yy-a2);
        }
    }
    return;
}



void solve(){
     //cout << "CASE " << endl;
    int n; cin >> n;
    ll ans = 0;
    unordered_map<ll, ll> m;

    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    rep(i, 0, n){
        rep(j, i+1, n){
            vector<ll> xs(0);
            getx(xs, a[i], a[j]);
            for(auto x: xs){
                m[x]++;
                ans = max(m[x], ans);
                //cout << "x " << x << endl;
            }
        }
    }
    //cout << "ANS " << ans << endl;
    //ans = 1;
    ll l = 0, r = 1e6;
    ll k;
    while(l < r){
        k = (l+r+1)/2;
        if((k*(k+1)/2) > ans){
            r = k-1;
        }
        else l = k;
    }
    cout << l+1 << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}