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

vector<pii> moves = {{1,3}};

void solve(){
    int n; cin >> n;
    rep(ii, 0, n-1){
        vector<pii> temp = moves;
        for(auto &p: temp){
            if(p.fi > 1) p.fi = 5 - p.fi;
            if(p.se > 1) p.se = 5 - p.se;
        }
        temp.push_back({1, 3});

        for(auto p: moves){
            pii add = p;
            if(add.fi < 3) add.fi = 3 - add.fi;
            if(add.se < 3) add.se = 3 - add.se;
            temp.push_back(add);
        }
        moves = temp;
    }
    cout << moves.size() << endl;
    for(auto p: moves) cout << p.fi << ' ' << p.se << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}