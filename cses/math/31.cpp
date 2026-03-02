#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<long double> a(101);
vector<vector<long double>> leqi(101, vector<long double>(101, 1)); //probabilidad de que a[i] sea menor o igual a j
vector<long double> rr(101);
int n;

long double expected(int l, int r){ //V.E. de inversiones entre [l,m] y [m+1,r]
    if(l == r) return 0;
    int m = (l+r)/2;
    long double ans = expected(l, m) + expected(m+1, r);
    rep(i, 1, 101){
        long double lefteqim1 = 0; //igual a i+1 de lado izq
        long double rightleqi = 0; //menores o iguales que i
        rep(j, l, m+1){
            if(rr[j] >= i+1) lefteqim1 += 2.0/rr[j];
        }
        rep(j, m+1, r+1){
            rightleqi += leqi[j][i];
        }
        ans += lefteqim1 * rightleqi;
    }
    return ans;
}

long double expected2(int l, int r){
    r++; l++;
    long double ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            long double add = 0;
            //casos totales: r[i]r[j], casos favorables = r[i]r[j]/2 - r[i]*(r[j]-r[i]) o + (r[i]-r[j])*r[j]
            if(rr[i] > rr[j]){
                add = -1+2*rr[i]-rr[j];
                add /= rr[i];
            }
            else{
                add = rr[i]-1;
                add /= rr[j];
            }
            //prob de que a[i] > a[j] es a[i] 
            ans+= add;
        }
    }
    return ans;
}

void solve(){
    cin >> n;
    rr = vector<long double>(n); rep(i, 0, n) cin >> rr[i];
    rep(i, 0, n) rep(j, 1, rr[i]) leqi[i][j] = (long double)j/(long double)rr[i];
    // rep(i, 0, n){
    //     rep(j, 1, rr[i]+1) cout << leqi[i][j] << ' ';
    //     cout << endl;
    // }
    long double ans = expected(0, n-1);
    long double ans2 = ans*1000000;
    cout << fixed << setprecision(12) << fabsl(ans2 - nearbyint(ans2)) << endl;
    if(fabsl(ans2 - nearbyint(ans2)) <= 0.000000000000001){
        cout << "xd";
        ans = nearbyint(ans2)/2;
        ans = nearbyint(ans);
        ans/=1000000;
        cout << fixed << setprecision(6) << ans << endl;
        return;
    } 
    else{
        cout << fixed << setprecision(6) << ans/2 << endl;
        cout << fixed << setprecision(15) << expected(0, n-1);
    }
    
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}