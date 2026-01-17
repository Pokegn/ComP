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
    ll n,m; cin >> n >> m;
    //cout << 1 << ' ' << 1 << endl;
    ll l = 1, r = m;

    vlli inc(n);
    for(int i=0; i<n; i++) inc[i] = i+1;
    vlli dec(n);
    for(int i=0; i<n; i++) dec[i] = n-i;

    vlli orden(0);
    for(int i=0; i<n; i++){
        orden.push_back(inc[i]);
        orden.push_back(dec[i]);
    }

    while(l<=r){
        if(l==r){
            for(int i=0; i<n; i++){
                cout << orden[i] << ' ' << l << endl;
            }
        }
        else{
            for(int i=0; i<2*n; i++){
                if(i%2==0){
                    cout << orden[i] << ' ' << l << endl;
                }
                else{
                    cout << orden[i] << ' ' << r << endl;
                }
            }
        }
        l++;
        r--;
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