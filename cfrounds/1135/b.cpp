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

ll x(ll n){
    return n*(n+1)/2;
}

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int unos =0, ceros = 0;
    rep(i, 0, n){
        if(s[i] == '0') ceros++;
        else unos++;
    }
    if(unos < ceros) swap(unos, ceros);
    while(ceros > 0 && k > 0){
        unos++, ceros--;
        k--;
    }
    cout << x(unos) + x(ceros) + 1 << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}