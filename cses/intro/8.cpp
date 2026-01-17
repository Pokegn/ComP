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
    if(n%4 == 1 || n%4 == 2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(n%4 == 0){
        cout << n/2 << endl;
        ll m = n/4;
        for(int i=0; i<m; i++){
            cout << 4*i+1 << ' ' << 4*i+4 << ' ';
        }

        cout << n/2 << endl;
        for(int i=0; i<m; i++){
            cout << 4*i+2 << ' ' << 4*i+3 << ' ';
        }
    }
    if(n%4 == 3){
        cout << 2*(n/4)+1 << endl;
        ll m = n/4;
        for(int i=0; i<m; i++){
            cout << 4*i+4 << ' ' << 4*i+7 << ' ';
        }
        cout << 3 << endl;

        cout << 2*(n/4)+2 << endl;
        for(int i=0; i<m; i++){
            cout << 4*i+5 << ' ' << 4*i+6 << ' ';
        }
        cout << 1 << ' ' << 2 << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}