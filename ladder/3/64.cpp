#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

int ispsz = 10e6+10;
vector<bool> isp(ispsz, true);
void calculaprimos(){
    isp[0] = false; isp[1] = false;
    for (int i = 2; i <= 10e6+10; i++) {
        if (isp[i] && (long long)i * i <= ispsz) {
            for (int j = i * i; j <= ispsz; j += i)
                isp[j] = false;
        }
    }
}

void solve(){
    calculaprimos();
    int n; cin >> n;
    vlli a(n);
    for(lli &x: a) cin >> x;
    lli x;
    lli y; 
    forn(i, 0, n){
        x = a[i];
        y = sqrt(x);
        if((y*y == x) && (isp[y] == true)) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}