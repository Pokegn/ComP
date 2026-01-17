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
    ll a=0,b=0,x;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x>1) b++;
        else a++;
    }

    if(b == 0){
        if(a%2 == 0){
            cout << "Bob" << endl;
            return;
        }
        else{
            cout << "Alice" << endl;
            return;
        }
    }

    if(a%2 == 1){
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}