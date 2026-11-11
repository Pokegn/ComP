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
    ll res = 0;
    rep(i, 1, n+1){
        res ^= i;
    }

    int pot = 1;
    while(pot <= n) pot*=2;

    set<int> ones;

    while(pot > 1){
        if((res^pot) > res){
            ones.insert(pot/2);
            res^=(pot/2);
            res^=(pot);
        }
        pot/=2;
    }
    rep(i, 1, n+1){
        if(ones.find(i) != ones.end()){
            cout << 1 << ' ';
        }
        else cout << 0 << ' ';
    }
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}