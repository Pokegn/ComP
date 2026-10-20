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

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string s, int lim = 256){ //or vector<int>
        s.push_back(0); int n = sz(s), k = 0, a, b;
        vi x(all(s)), y(n), ws(max(n, lim));
        sa = lcp = y, iota(all(sa), 0);
        for(int j = 0, p = 0; p<n; j = max(1, j*2), lim = p){
            p = j, iota(all(y), n-j);
            rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i-1];
            for(int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i-1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a+j] == y[b+j]) ? p-1 : p++;
        }
        for(int i=0, j; i < n-1; lcp[x[i++]] = k)
            for(k && k--, j = sa[x[i]-1]; s[i+k] == s[j+k]; k++);
    }
};

void solve(){
    string s; cin >> s;
    auto sfx = SuffixArray(s);
    int n = sz(s);
    int idx = 0;
    int res = 0;
    rep(i, 1, n+1){
        if(res < sfx.lcp[i]){
            res = sfx.lcp[i];
            idx = sfx.sa[i];
        }
    }
    string ans = "";
    rep(i, 0, res){
        ans += s[idx+i];
    }

    if(res == 0){
        cout << -1 << endl;
        return;
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