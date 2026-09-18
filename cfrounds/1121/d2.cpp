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
    int n; cin >> n;
    vector<string> resp = 
    {"1",
    "01",
    "101",
    "0101",
    "01010",
    "001010",
    "0010100",
    "00101001",
    "000101001",
    "0001000100"};

    if(n < 10){
        cout << resp[n-1] << endl;
        return;
    }

    cout << "1";
    rep(i, 0, (n-1)/3){
        cout << "0";
    }
    cout << "1";
    cout << "0";
    rep(i, 0, (n-4)/6){
        cout << "00";
    }
    cout << "1";
    ll rem = n-4-(n-1)/3-2*((n-4)/6);
    rep(i, 0, rem){
        cout << "0";
    }
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