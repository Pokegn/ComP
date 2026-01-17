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
    string s; cin >> s;
    int n = s.length();
    reverse(s.begin(), s.end());
    vector<long double> a(n+1);
    for(int i=1; i<=n; i++){
        if(s[i-1] == 'C') a[i] = 1;
        else a[i] = -1;
    }

    vector<long double> mmd(n+1, 0);
    vector<long double> ans(n+1, 0);
    vector<long double> sumans(n+1, 0);
    mmd[1] = a[1];
    ans[1] = 1;
    sumans[1] = 1;

    for(int i=2; i<=n; i++){
        mmd[i] = mmd[i-1]+i*a[i];
        ans[i] = mmd[i]*a[i]/i+sumans[i-1]/i;
        sumans[i] = sumans[i-1]+ans[i];
    }

    cout << setprecision(11) << (n-ans[n])/2 << endl;

}

int main(){
    freopen("foreign.in", "r", stdin);
    freopen("foreign.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}