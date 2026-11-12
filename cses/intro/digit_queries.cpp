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

ll val(ll n){ //el n-esimo digito de que numero es
    if(n == 0) return 0;
    ll dig = 1;
    ll condig = 9;
    ll cum = 0;
    while(cum + dig*condig < n){
        cum += dig*condig;
        dig++;
        condig*=10;
    }
    //tiene dig digitos
    ll m = n-cum; //si solo cuento a los de dig digitos en que numero voy
    m--;
    ll cual = m/dig;
    ll ans = 1;
    rep(i, 1, dig) ans *= 10;
    return ans + cual;
} 

void solve(){
    ll k; cin >> k;
    ll v = val(k);
    ll first = k;
    while(val(first) == v) first--;
    first++;

    ll digit = k - first;
    string s = to_string(v);

    cout << s[digit] << endl;

    // cout << val(k) << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}