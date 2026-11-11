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
    int a,b; cin >> a >> b;
    // int e = (n*(n+1))/2 - a - b; 
    set<int> awin, bwin;
    for(int i=n; i>=0; i--){
        if(a >= i){
            awin.insert(i);
            a-=i;
        }
        if(b>=i){
            bwin.insert(i);
            b -= i;
        }
    }

    if(a>0 || b>0 || (int)(sz(awin)+sz(bwin)) > n){
        cout << "NO" << endl;
        return;
    }

    vi alose, blose;
    vi awinn, bwinn;

    rep(i, 1, n+1){
        if(awin.find(i) == awin.end()) alose.push_back(i);
        else awinn.push_back(i);
        if(bwin.find(i) == bwin.end()) blose.push_back(i);
        else bwinn.push_back(i);
    }

    sort(all(awinn));
    sort(all(bwinn));





    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}