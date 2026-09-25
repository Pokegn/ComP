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

array<vi, 2> manacher(const string& s) {
    int n = sz(s);
    array<vi,2> p = {vi(n+1), vi(n)};
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
    int t = r-i+!z;
    if (i<r) p[z][i] = min(t, p[z][l+t]);
    int L = i-p[z][i], R = i+p[z][i]-!z;
    while (L>=1 && R+1<n && s[L-1] == s[R+1])
    p[z][i]++, L--, R++;
    if (R>r) l=L, r=R;
    }
    return p;
}


void solve(){
    string s; cin >> s;
    int n = sz(s);
    vi ans(n, 0);
    auto a = manacher(s); //god
    ans[0] = 1;

    vi lim(n, 0);
    rep(i, 0, n){
        lim[i+a[1][i]] = max(lim[i+a[1][i]], 1+2*a[1][i]);
    }
    rep(i, 1, n){
        lim[i+a[0][i]-1] = max(lim[i+a[0][i]-1], 2*a[0][i]);
    }

    // rep(i, 0, n){
    //     cout << a[0][i] << ' ' << a[1][i] << ' ' << lim[i] <<endl;
    // }

    int curr = 0;
    for(int i=n-1; i>=0; i--){
        curr = max(curr, lim[i]);
        curr = max(curr, 1);
        ans[i] = curr;
        curr-=2;
    }

    rep(i, 0, n){
        cout << ans[i] << ' ';
    }

    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}