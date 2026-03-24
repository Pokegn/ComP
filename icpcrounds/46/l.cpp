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

void solve(){
    ll n; cin >> n;
    cout << "YES" << endl;
    ll pot = n&(n-1);
    if(pot !=0){
        cout << n-pot << ' ' << pot << endl;
        return;
    }
    if(n == 1){
        cout << 2 << ' ' << 3 << endl;
        return;
    }
    else{
        cout << n+1 << ' ' << 1 << endl;
    }
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
   // cin >> t;
    while(t--) solve();
    return 0;
}