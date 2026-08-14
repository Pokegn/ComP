//https://codeforces.com/group/GHvtTrfZFd/contest/706597/problem/D

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

int n;
void minreq(vi &a, map<int, int> &musteat){
    int curr = 0;
    //cuantos tengo que comer para que queden i mas rojas que azules
    rep(i, 0, n){
         if(a[i] == 1) curr++;
         else curr--;
    }

    rep(i, 0, n+1){
        musteat[i] = musteat[-i] = 1000000;
    }

    musteat[curr] = 0;

    rep(i, 0, n){
        if(a[i] == 1) curr--;
        else curr++;
        musteat[curr] = min(musteat[curr], i+1);
    }
    return;
}

void solve(){
    cin >> n;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    reverse(all(a));

    map<int, int> eatleft, eatright;
    minreq(a, eatleft);
    minreq(b, eatright);

    int ans = 2000000;
    for(int i = -n; i <= n; i++){
        ans = min(ans, eatleft[i] + eatright[-i]);
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