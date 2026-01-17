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
    ll a,b,c;
    map<ll, ll> solved;
    map<pair<ll, ll>, ll> done;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        if(done[{a,b}] == 1){
            cout << 0 << endl;
            continue;
        } 
        solved[a]++;
        done[{a,b}] = 1;
        if(c<240){
            cout << b << endl;
            continue;
        }
        else{
            if(solved[a]>3) cout << 0 << endl;
            else cout << b << endl;
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