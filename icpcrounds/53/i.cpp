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
    string ss; cin >> ss;
    vector<int> s(n); rep(i, 0, n) s[i] = (int)(ss[i]-'0');

    vector<int> f(10);
    rep(i, 1, 10){
        cin >> f[i];
    }

    int idx = 0;
    int idxr = 0;
    while(idx <= n-1 && f[s[idx]] <= s[idx]){
        idx++;
    }
    if(idx < n){
        idxr = idx;
        while(idxr <= n-1 && f[s[idxr]] >= s[idxr]){
            idxr++;
        }
        idxr--;
    }
    rep(i, 0, n){
        if(i >= idx && i <= idxr){
            cout << f[s[i]];
        }
        else cout << s[i];
    }
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