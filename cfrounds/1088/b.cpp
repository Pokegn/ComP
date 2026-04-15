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
#define MOD 676767677

void solve(){
    int x,y; cin >> x >> y;
    int sum = x-y;
    vector<int> a;
    rep(i, 0, x) a.push_back(1);
    rep(i, 0, y) a.push_back(-1);

    int div = 0;
    if(sum == 0) cout << 1 << endl;
    else{
        if(sum<0) sum = -sum;
        rep(i, 1, sum+1) if(sum%i == 0) div++;
        cout << div << endl;
    }
    for(auto x: a) cout << x << ' ';
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}