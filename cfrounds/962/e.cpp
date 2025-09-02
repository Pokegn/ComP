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
#define MOD 1000000007

void solve(){
    string s; cin >> s;
    lli n = s.length();
    vlli str(n, 0);

    forn(i,0 ,n){
        str[i] = (lli) s[i] - '0';
    }

    vlli sum(n+1, 0);
    forn(i, 1, n+1){
        if(str[i-1] == 0){
            sum[i]--;
        }
        else sum[i]++;
        sum[i]+=sum[i-1];
    }

    vlli sumadesumas(2*n+2, 0);
    sumadesumas[n] = 1;
    sumadesumas[n+sum[1]]+=1+1;
    vlli ans(n+1, 0);
    forn(i, 2, n+1){
        ans[i] = 2*ans[i-1]-ans[i-2]%MOD;
        ans[i] +=sumadesumas[n+sum[i]]%MOD;
        sumadesumas[n+sum[i]]+=i+1;
        sumadesumas[n+sum[i]]%=MOD;
        ans[i]=(ans[i]%MOD+MOD)%MOD;
    }

    cout << ans[n] << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}