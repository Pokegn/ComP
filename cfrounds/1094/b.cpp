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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,m; cin >> n >> m;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    vector<ll> x(m); rep(i, 0, m) cin >> x[i];
    priority_queue<ll> odd, even;
    rep(i, 1, n+1){
        if(i%2 == 0) even.push(a[i-1]);
        else odd.push(a[i-1]);
    }

    int oddcount = 0;
    int evencount = 0;
    rep(i, 0, m){
        if(x[i]%2 == 0) evencount++;
        else oddcount++;
    }
    //cout << oddcount << ' ' << evencount << ' ';

    ll maxsum = 0;
    bool done = false;
    while(oddcount>0){
        if(odd.size() == 0) break;
        if(odd.top() < 0 && done) break;
        maxsum += odd.top();
        odd.pop();
        oddcount--;
        done = true;
    }

    done = false;
    while(evencount>0){
        if(even.size() == 0) break;
        if(even.top() < 0 && done) break;
        maxsum += even.top();
        even.pop();
        evencount--;
        done = true;
    }

    ll sum = 0;
    rep(i,0 , n) sum+=a[i];
    cout << sum-maxsum << endl;
    return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}