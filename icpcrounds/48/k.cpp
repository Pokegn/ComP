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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int h,w,k,i,t; cin >> h >> w >> k >> i >> t;
    k--; i--; t--;
    string s;
    rep(j, 0, i) s+='i';
    rep(j, 0, k) s+='k';
    rep(j, 0, t) s+='t';
    s+="kit";

    rep(j, 0, s.size()){
        if(j>0 && j%w == 0) cout << endl;
        cout << s[j];
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