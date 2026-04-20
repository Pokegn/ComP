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
    int n; cin >> n;
    if(n == 1){
        cout << "WALK" << endl;
    }
    if(n == 2){
        cout << "NO" << endl;
    }
    if(n == 3){
        cout << "NO" << endl;
    }
    if(n == 4){
        cout << "NO" << endl;
    }
    if(n == 5){
        cout << "YES" << endl;
    }
    if(n == 6){
        cout << "YES" << endl;
    }
    if(n == 7){
        cout << "backwards" << endl;
    }
    if(n == 8){
        cout << 7 << endl;
    }

    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}