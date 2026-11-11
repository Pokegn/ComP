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
    vi sperm(8);
    iota(all(sperm), 0);

    vector<vi> isBlocked(8, vi(8));

    vector<string> ss(8); rep(i,0,8) cin >> ss[i];

    rep(i, 0, 8) rep(j, 0, 8) isBlocked[i][j] = (ss[i][j] == '.' ? 0:1);

    int ans = 0;
    rep(ii, 0, 40500){
        bool isValid = true;
        rep(i, 0, 8) rep(j, 0, i) if(abs(i-j) == abs(sperm[i]-sperm[j])) isValid = false;
        rep(i, 0, 8) if(isBlocked[i][sperm[i]]) isValid = false;
        if(isValid) ans++;
        next_permutation(all(sperm));
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}