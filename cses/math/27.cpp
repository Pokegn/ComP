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

vector<ll> tri;

void solve(){
    ll n; cin >> n;
    for(int i=0; i<tri.size(); i++){
        if(tri[i] == n){
            cout << 1 << endl;
            return;
        }
    }

    ll l = 0, r = tri.size()-1;
    while(l<=r){
        ll curr = tri[l]+tri[r];
        if(curr == n){
            cout << 2 << endl;
            return;
        }
        if(curr>n) r--;
        else l++;
    }

    cout << 3 << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    for(ll i=0; i*i<=2*(1e12); i++){
        tri.push_back(i*(i+1)/2);
    }
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}