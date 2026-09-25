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

vi Z(const string &S){
    vi z(sz(S));
    int l = -1, r = -1;
    rep(i, 1, sz(S)){
        z[i] = i>=r ? 0 : min(r-i, z[i-l]);
        while(i+z[i] < sz(S) && S[i+z[i]] == S[z[i]]) 
            z[i]++;
        if(i+z[i] > r) l = i, r = i+z[i];
    }
    return z;
} //fokass

void solve(){
    string s; cin >> s;
    int n = sz(s);
    auto z = Z(s);
    set<int> ans; ans.insert(n);
    rep(i, 0, n){
        if(z[i] == n-i){
            cout << i << ' ';
        }
    }
    cout << n << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}