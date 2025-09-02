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
    lli n; cin >> n;
    vlli a(n+1);
    vlli b(n+1);
    lli s = 0;
    forn(i, 1, n+1){
        cin >> b[i];
        s+=b[i];
    }
    b[0] = b[n];

    lli modo = n*(n+1);
    modo/=2;

    if(s%modo !=0){
        cout << "NO" << nl;
        return;
    }
    s /= modo;
    forn(i, 1, n+1){
        a[i] = s + b[i-1] - b[i];
        if(a[i]%n != 0 || a[i]<=0){
            cout << "NO" << nl;
            return;
        }
        a[i]/=n;
    }

    cout << "YES" << nl;
    forn(i, 1, n+1){
        cout << a[i] << ' ';
    }
    cout << nl;
    
    
    // forn(i, 1, n+1){
    //     c[i] = b[i-1] - b[i]; //a[i] guarda a n*a_i - s
    // }
    // lli x = 0;
    // forn(i, 1, n+1){
    //     x += i*c[n+1-i]; //x = c_n + 2c_n-1 + ... + nc_1 = n*(a_n + 2a_n-1 + ... + na_1) - s*n(n+1)/2 
    // }
    // forn(i, 1, n+1){
    //     cout << c[i] << ' ';
    // }
    // cout << nl;
    // if(x != n*b[n]){
    //     cout << "NO" << nl;
    //     return;
    // }
    // cout << "YES" << nl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}