#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    map<ll, ll> count;
    vlli repetidos(0);

    ll n; cin >> n; vlli a(n); for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        count[a[i]]++;
        if(count[a[i]]>=4){
            cout << "YES" << endl;
            return;
        }
    }
    
    map<ll, ll> count2;
    for(int i=0; i<n; i++){
        count2[a[i]]++;
        if(count[a[i]] > 1 && count2[a[i]] == count[a[i]]) repetidos.push_back(a[i]);
    }

    if(repetidos.size()>1){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}