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
    ll n,k; cin >> n >> k;
    vector<ll> a(k); for(int i=0; i<k; i++) cin >> a[i];
    vector<vector<ll>> ronda(n, vector<ll>(0));
    for(int i=0; i<n; i++){
        ronda[0].push_back(i);
    }
    
    vector<bool> fuera(n, false);
    ll elim = -1;
    ll idx = -1;
    ll lider = 0;
    
    for(int r = 0; r<k; r++){

        idx = (lider+a[r])%(n-r);
        elim = ronda[r][idx];
        cout << elim+1 << ' ';
        fuera[elim] = true;
        if(idx+1 == n-r) lider = 0;
        else lider = idx;

        for(int i=0; i<n; i++){
            if(!fuera[i]){
                ronda[r+1].push_back(i);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}