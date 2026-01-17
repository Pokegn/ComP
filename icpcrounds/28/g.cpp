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
    ll n,m,k; cin >> n >> m >> k;
    ll ans = 0;
    ll finans = 0;
    ll maxsum; // maxima suma en los que me quedan despues de quitar m todas las veces posibles
    maxsum = m*(k-1);
    for(ll sum = (n%k); sum<=maxsum && sum<=n; sum+=k){ //tengo suma sum
        ll res1 = sum/m;
        ll res2 = sum/m+1;
        ll n2 = sum%m;
        ll n1 = m-n2;
        //primero quito a los ks, luego res2, luego res1
        ll ans = 0;
        ll j = (n-sum)/k; // n = sum+jk
        ans = (sum*j) + k*(j*(j+1))/2; //sum+k + sum+2k + ... + sum+jk
        ans+= (m*(m+1)/2)*res1;
        ans+= (n2*(n2+1)/2);
        finans = max(finans, ans);
    }

    cout << finans << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}