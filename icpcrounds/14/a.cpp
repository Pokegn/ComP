#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    string s; cin >> s;
    long double n;
    ll sz = s.length();
    vector<long double> d;
    n = 0;
    long double ans = 0;
    long double div = 10;

    for(int i=0; i<sz-1; i++){
        d.push_back((long double)(s[i]-'0')); //d[i] lo vuelvo el digito i
        d[i]/=div; //ahora d[i] es el digito 3/10^2
        n+=d[i];
        div*=10;
        ans+=9*n;
    }
    int i = sz-1;
    d.push_back((long double)(s[i]-'0')); //d[i] lo vuelvo el digito i
    d[i]/=div; //ahora d[i] es el digito 3/10^2
    n+=d[i];
    div*=10;
    ans+=10*n;

    cout << setprecision(11) << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}