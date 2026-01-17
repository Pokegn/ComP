#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n; cin >> n;
    if(n==1){
        cout << 1 << endl;
        return;
    }
    if(n <=3 ){
        cout << "NO SOLUTION" << endl;
        return;
    }
    vlli a1,a2;
    for(int j=1; j<=n/2; j++){
        a1.push_back(j);
    }
    for(int j=n/2+1; j<=n; j++){
        a2.push_back(j);
    }
    for(int i=0; i<n/2; i++){
        cout << a2[i] << ' ' << a1[i] << ' ';
    }
    if(a1.size()<a2.size()){
        cout << a2.back() << ' ';
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}