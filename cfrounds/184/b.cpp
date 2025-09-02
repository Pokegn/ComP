#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli p, q; cin >> p >> q;
    lli g = __gcd(p, q);
    p/=g;
    q/=g;

    int n; cin >> n;
    vlli a(n);
    forn(i, 0, n){
        cin >> a[i];
    }
    if(a[n-1] == 1 && n>1){
        a[n-2] +=1;
        n--;
    }

    forn(i, 0, n){
        if(q<=0){
            cout <<"NO" << nl;
            return;
        }
        if((lli)(p/q) != a[i]){
            //cout << p << ' ' << q << ' ' << a[i] << ' ';
            cout << "NO" << nl;
            return;
        }
        p -= a[i]*q;
        swap(p, q);
    }
    if(q == 0) cout << "YES" << nl;
    else cout << "NO" << nl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 

    while(t--) solve();
    return 0;
}