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
#define MOD 1000000007

vvlli a(2010, vlli(2010, 0));
lli p =0,q =0;
lli n;
void llena(){
    a[0][0] = 1;
    forn(i, 0, 2010){
        forn(j, 0, 2010){
            if(j>i) continue;
            if(j>0) a[i][j]+=a[i][j-1];
            if(i>0) a[i][j]+=a[i-1][j];
            a[i][j]%=MOD;
        }
    }
}

lli calcula(lli x, lli y, lli cm){
    if(y-cm > x) return 0;
    if(x>2009 || y>2009 || n/2-x-p>2009 || n/2-y-q>2009) return 0;
    lli ans = a[x][y];
    if(n/2-x-p<0 || n/2-y-q<0) return 0;
    ans*= a[n/2 - y - q][n/2 - x - p];
    ans%=MOD;
    return ans;
}



void solve(){
    lli m; cin >> n >> m;
    string s; cin >> s;
    if(n%2 == 1){
        cout << 0 << nl;
        return;
    }
    lli cuenta = 0;
    lli cuentamin = 0;
    lli ans = 0;
    forn(i, 0, s.length()){
        if(s[i] == '('){
            p++;
            cuenta++;
        } 
        else{
            cuenta--;
            q++;
        } 
        cuentamin = min(cuenta, cuentamin);
    }

    forn(i, 0, 2001){
        forn(j, 0, 2001){
            ans+=calcula(i, j, cuentamin);
            ans%=MOD;
        }
    }

    // forn(i, 0, 10){
    //     forn(j, 0, 10){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << nl;
    // }

    cout << ans << nl;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    llena();
    solve();
    return 0;
}
