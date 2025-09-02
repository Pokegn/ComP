#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, a, b;
    cin >> n >> a >> b;
    vlli vec(n); forn(i, 0, n) cin >> vec[i];
    lli mcd = __gcd(a, b);
    if(mcd == 1){
        cout << 0 << nl;
        return;
    }
    forn(i, 0, n) vec[i] = (vec[i]%mcd + mcd)%mcd;
    sort(vec.begin(), vec.end());
    lli maxdif = 0;
    vec.push_back(vec[0]+mcd);
    forn(i, 1, n+1){
        maxdif = max(maxdif, vec[i]-vec[i-1]);
    }
    cout << mcd-maxdif << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}