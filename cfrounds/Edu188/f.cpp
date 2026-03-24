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
#define MOD 998244353

long long fexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> k(m);
    rep(i, 0, n) cin >> a[i];
    rep(j, 0, m) cin >> k[j];

    vector<pair<ll, ll>> pairs;
    rep(i, 0, n){
        pairs.push_back({a[i], i});
    }
    sort(all(pairs));

    set<int> s;
    set<int> s2;
    vector<ll> count(n, 0);
    ll left, right;
    rep(i, 0, n){
        int x = pairs[i].second;
        auto lb=s.lower_bound(-x); 
        if(lb!=s.end()){
            left = i-*(lb);
        } 
        else{
            left = i;
        }
        s.insert(-x);


        lb=s2.lower_bound(x); 
        if(lb!=s2.end()){
            right = *(lb)-i;
        }   
        else{
            right = n-i+1;
        }
        s2.insert(x);
        count[i] = (right*left);
    }


    

    
    rep(i, 0, n){
        int x = pairs[i].second;
        
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}