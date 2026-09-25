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

vi pi(const string &s){
    vi p(sz(s));
    rep(i,1,sz(s)){
        int g = p[i-1];
        while(g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

void solve(){
    string s,t; cin >> s >> t;
    string xd = t+"#"+s;
    vi kmp = pi(xd);
    int ans = 0;
    for(int i = sz(t)+1; i<sz(kmp); i++){
        if(kmp[i] == sz(t)){
            ans++;
        }

    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}