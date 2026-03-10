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

vector<ll> ans;
ll tt;
vector<ll> respuestafinal;

bool canwin(vector<ll> &a, vector<ll> &t, ll s){ 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ans = vector<ll> (0);
    int n = a.size();
    rep(i, 0, n){
        if(s <= a[i]) pq.push({t[i],i});
    }
    int sz = 0;
    ll tiempo = 0;
    while(sz < s && !pq.empty() && tiempo + pq.top().first <= tt){
        tiempo += pq.top().first;
        sz++;
        ans.push_back(pq.top().second);
        pq.pop();
    }

    if(ans.size() == s) {
        swap(respuestafinal, ans);
        return true;
    }
    return false;

}

void solve(){
    int n; cin >> n;
    cin >> tt;
    vector<ll> a(n), t(n);
    rep(i, 0, n) cin >> a[i] >> t[i]; 
    ll l = 0, r = n;
    while(l < r){ //0 a m o m+1 a r
        ll m = (l+r+1)/2;
        if(canwin(a, t, m)){
            l = m;
        } 
        else{
            r = m-1;
        }
    }
    cout << l << endl;
    cout << respuestafinal.size() << endl;
    for(auto xd: respuestafinal) cout << xd+1 << ' ';
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}