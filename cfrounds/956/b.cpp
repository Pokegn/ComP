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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,m; cin >> n >> m;
    vvlli a(n, vlli(m));
    vvlli b(n, vlli(m));
    vlli sumfa(n, 0);
    vlli sumca(m, 0);
    vlli sumfb(n, 0);
    vlli sumcb(m, 0);
    char c;
    forn(i, 0, n){
        forn(j, 0, m){
            cin >> c;
            a[i][j] = (lli)(c-'0');
            //cout << a[i][j];
        }
        //cout << nl;
    }
    forn(i, 0, n){
        forn(j, 0, m){
            cin >> c;
            b[i][j] = (lli)(c-'0');
            //cout << b[i][j];
        }
        //cout << nl;
    }
    //return;
    //cout << "XD";
    forn(i, 0, n){
        forn(j, 0, m){
            sumfa[i]+=a[i][j];
            sumca[j]+=a[i][j];
            sumfb[i]+=b[i][j];
            sumcb[j]+=b[i][j];
        }
    }

    // forn(i, 0, n){
    //     cout << sumfa[i]%3 << ' ' << sumfb[i]%3 << nl;
    // }
    // forn(j, 0, m){
    //     cout << sumca[j]%3 << ' ' << sumcb[j]%3 << nl;
    // }
    // return;

    forn(i, 0, n){
        if(sumfa[i]%3!=sumfb[i]%3){
            cout << "NO" << nl;
            return;
        }
    }
    forn(i, 0, m){
        if(sumca[i]%3!=sumcb[i]%3){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
    return;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}