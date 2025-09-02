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

vlli a;
vlli dp;
vlli suma;
vlli bound;

void dpsolve(lli i, lli r, lli n){
    if(i>n-1) return;
    if(dp[i]!=-1) return;
    if(suma[i]>r || suma[i] == -1){
        dpsolve(i+1, r, n);
        dp[i] = dp[i+1];
    }
    else{
        dpsolve(bound[i]+1, r, n);
        dpsolve(i+1, r, n);
        dp[i] = max(dp[i+1], dp[bound[i]+1]+1);
    }
}

void solve(){
    lli n, l ,r; cin >> n >> l >> r;
    a.assign(n, 0); forn(i, 0, n) cin >> a[i];
    bound.assign(n,-1); //el primer indice tal que la suma de i a j es mayor o igual que l
    suma.assign(n,-1); //la menor suma mayor o igual que l que se puede obtener empezando con i

    lli right = 0;
    lli sum = 0;
    forn(i, 0, n){
        if(i>0){
            sum-=a[i-1];
        }
        //if(right>=n) break;
        while(sum<l && right<n){
            sum+=a[right];
            right++;
        }
        if(sum<l) break;
        if(sum>r){
            bound[i] = -1;
            suma[i] = -1;
            continue;
        }
        bound[i] = right-1;
        suma[i] = sum;

    }

    dp.assign(n+1, -1);
    dp[n-1] = ((a[n-1] <= r && a[n-1] >= l) ? 1:0);
    dp[n] = 0;
    dpsolve(0, r, n);
    //forn(i,0, n) cout << dp[i]  << ' ';
    cout << dp[0] << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}