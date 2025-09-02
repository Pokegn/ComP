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

vlli amax;
vlli bmax;
lli m,n;

void solve(){
    cin >> n >> m;
    lli kmax;
    if(n*2 <= m) kmax = n;
    else if(m*2 <= n) kmax = m;
    else kmax = (n+m)/3;
    cout << kmax << nl;
    vlli a(n, 0);
    vlli b(m, 0);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, m) cin >> b[i];

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    amax = vlli(n+1, 0);
    lli ntomados = 2;
    lli l = 0, r = n-1;
    while(ntomados<=n){
        amax[ntomados] = amax[ntomados-2] + a[r]-a[l];
        if(ntomados+1<=n) amax[ntomados+1] = amax[ntomados];
        l++;
        r--;  
        ntomados+=2;
    }

    bmax = vlli(m+1, 0);
    lli mtomados = 2;
    l = 0, r = m-1;
    while(mtomados<=m){
        bmax[mtomados] = bmax[mtomados-2] + b[r]-b[l];
        if(mtomados+1<=m) bmax[mtomados+1] = bmax[mtomados];
        l++;
        r--;  
        mtomados+=2;
    }

    // cout << amax[0] << ' ' << amax[2] << ' ' << amax[4] << ' ' << amax[6] << nl;
    // cout << bmax[0] << ' ' << bmax[2] << ' ' << bmax[4] << ' ' << bmax[6] << nl;

    forn(i, 1, kmax+1){
        l = 0;
        r = i;
        while (r - l >=3) {
            lli m1 = l + (r - l) / 3;
            lli m2 = r - (r - l) / 3;
            lli f1 = ((i+m1<=n && 2*i-m1<=m) ? amax[2*m1] + bmax[2*(i-m1)] : (i+m1>n ? n-i-m1 : m+m1-i));      
            lli f2 = ((i+m2<=n && 2*i-m2<=m) ? amax[2*m2] + bmax[2*(i-m2)] : (i+m2>n ? n-i-m2 : m+m2-i));
            if (f1 < f2)
                l = m1;
            else
                r = m2;
        }
        lli thisans = ((i+l<=n && 2*i-l<=m) ? amax[2*l] + bmax[2*(i-l)] : (i+l>n ? n-i-l : m+l-i));
        forn(j, l, r+1){
            thisans = max(thisans, ((i+j<=n && 2*i-j<=m) ? amax[2*j] + bmax[2*(i-j)] : (i+j>n ? n-i-j : m+j-i)));
        }
        cout << thisans << ' ';
    }
    cout << nl;


}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}