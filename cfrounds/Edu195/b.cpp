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
    string s; cin >> s; 
    ll n = sz(s);
    map<int, int> count;
    rep(i, 1, n-1){
        if(s[i]!=s[i-1] && s[i]!=s[i+1]){
            count[1]++;
        }
        if(s[i]==s[i-1] && s[i]==s[i+1]){
            count[-1]++;
        }
        count[0]++;
    }

    int ans = 0;
    rep(i, -1, 2){
        if(count[i] > 0) ans++;
    }

    cout << ans << endl;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}