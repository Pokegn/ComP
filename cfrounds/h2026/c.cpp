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
    ll k, n, m; cin >> n >> m >> k;
    ll left = k-1;
    ll right = n-k;
    if(right>left) swap(left, right); //left >= right
    ll ans = 1;

    if(m > 3*right-1){
        m-=3*right-1;
        ans+=m/2;
        ans+=2*right;
        cout << min(ans, n) << endl;
        return;
    }
    else{
        ll mult = (m-1)/3;
        ll r = (m-1)%3;
        if(r == 2) r = 1;
        ll res = 2*mult+1 + r;
        cout << min(n, res + 1) << endl;
        return;
    }

    if(k == n || k == 1){
        ans+=((m-1)/2)+1;
        cout << min(n, ans) << endl;
        return;
    }
    if(m == 1) ans++;
    else{
        ans+=(m/2)+1;
    }
    cout << min(n, ans) << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}