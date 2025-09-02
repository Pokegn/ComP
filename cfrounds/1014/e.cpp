#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using ll = long long;
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

ll binpow (ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a; res %= MOD;
        }
        a *= a; a %= MOD; n >>= 1;
    }
    return res;
}

void solve(){
    lli n, m; cin >> n >> m;
    vlli color(n*m+1, -1);
    lli k; cin >> k;
    lli x, y, c;
    bool flag = false;
    lli ans;

    forn(i, 0, k){
        cin >> x >> y >> c;
        color[(x-1)*m+(y-1)] = c;
    }
    
    forn(i, 0, n){
        forn(j, 0, m){
            if(color[i*m+j]!=-1) continue;
            if(((lli)i == 0 || (lli)i == n-1) && !((lli)j==0 || (lli)j == m-1)) flag = true;
            if(!((lli)i == 0 || (lli)i == n-1) && ((lli)j==0 || (lli)j == m-1)) flag = true;
            
        }
    }
    
    lli impo = 0;
    if(flag){
        ans=binpow(2, n*m-k-1);
        cout << ans%MOD << nl;
    }
    else{
        ans=binpow(2, n*m-k);
        forn(i, 0, n*m){
            if(color[i]==-1) color[i] = 1;
        }
        forn(i, 0, n){
            forn(j, 0, m){
                lli xd = i*m+j;
                if(i>0){
                    if(color[xd-m]!=color[xd]){
                        impo++;
                    } 
                    
                }
                if(i<n-1){
                    if(color[xd+m]!=color[xd]){
                        impo++;
                    } 
                    
                }
                if(j>0){
                    if(color[xd-1]!=color[xd]){
                        impo++;
                    } 
                    
                }
                if(j<m-1){
                    if(color[xd+1]!=color[xd]){
                        impo++;
                    } 
                    
                }
            }
        }
        impo/=2;
        if(impo%2 == 0) cout << ans%MOD << nl;
        else cout << 0 << nl;
    }

    
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}