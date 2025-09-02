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
    lli n,q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vvlli ax(27, vlli(n,0));
    vvlli bx(27, vlli(n,0));

    forn(i, 0, n){
        lli x = (lli) a[i]-'a';
        ax[x][i]++;
    }
    forn(i, 0, n){
        lli x = (lli) b[i]-'a';
        bx[x][i]++;
    }

    forn(i, 0, 27){
        forn(j, 0, n){
            if(j>0) bx[i][j] += bx[i][j-1];
            if(j>0) ax[i][j] += ax[i][j-1];
        }
    }

    lli ans;
    lli l, r;
    forn(query, 0, q){
        cin >> l >> r;
        ans = 0;
        forn(i,0,27){
            if(l == 1){
                ans+=abs(ax[i][r-1] - bx[i][r-1]);
            }
            else{
                ans+=abs((bx[i][r-1]-bx[i][l-2])-(ax[i][r-1]-ax[i][l-2]));
            }
        }
        cout << ans/2 << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}