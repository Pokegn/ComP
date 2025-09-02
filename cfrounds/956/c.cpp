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
    lli n; cin >> n;
    vlli a(n);
    vlli b(n);
    vlli c(n);
    forn(i,0 ,n) cin>> a[i];
     forn(i,0 ,n) cin>> b[i];
      forn(i,0 ,n) cin>> c[i];

    lli tot = 0;
    forn(i,0, n) tot+=a[i];
    lli req;
    req = (tot%3==0 ? (lli)tot/3 : (lli)tot/3+1);

    vlli sum(3, 0);
    lli i = 0;
    lli la, ra, lb, rb, lc, rc;

    la = 1;
    while(sum[0] < req && i<n){ //a,b,c
        sum[0]+=a[i];
        i++;
    }
    ra = i;
    lb = i+1;
    while(sum[1] < req && i<n){
        sum[1]+=b[i];
        i++;
    }
    rb = i;
    lc = i+1;
    while(sum[2] < req && i<n){
        sum[2]+=c[i];
        i++;
    }
    rc = i;
    if(sum[0] >= req && sum[1]>=req && sum[2]>=req){
        cout << la << ' ' << ra << ' '<< lb << ' '<< rb << ' '<< lc << ' '<< rc;
        cout << nl;
        return;
    }

    i = 0; sum = vlli(3,0);
    la = 1;
    while(sum[0] < req && i<n){ //a,c,b
        sum[0]+=a[i];
        i++;
    }
    ra = i;
    lc = i+1;
    while(sum[2] < req && i<n){
        sum[2]+=c[i];
        i++;
    }
    rc = i;
    lb = i+1;
    while(sum[1] < req && i<n){
        sum[1]+=b[i];
        i++;
    }
    rb = i;
    if(sum[0] >= req && sum[1]>=req && sum[2]>=req){
        cout << la << ' ' << ra << ' '<< lb << ' '<< rb << ' '<< lc << ' '<< rc;
        cout << nl;
        return;
    }

    i = 0; sum = vlli(3,0);
    lb = 1;
    while(sum[1] < req && i<n){ //b,a,c
        sum[1]+=b[i];
        i++;
    }
    rb = i;
    la = i+1;
    while(sum[0] < req && i<n){
        sum[0]+=a[i];
        i++;
    }
    ra = i;
    lc = i+1;
    while(sum[2] < req && i<n){
        sum[2]+=c[i];
        i++;
    }
    rc = i;
    if(sum[0] >= req && sum[1]>=req && sum[2]>=req){
        cout << la << ' ' << ra << ' '<< lb << ' '<< rb << ' '<< lc << ' '<< rc;
        cout << nl;
        return;
    }

    i = 0; sum = vlli(3,0);
    lb = 1;
    while(sum[1] < req && i<n){ //b,c,a
        sum[1]+=b[i];
        i++;
    }
    rb = i;
    lc = i+1;
    while(sum[2] < req && i<n){
        sum[2]+=c[i];
        i++;
    }
    rc = i;
    la = i+1;
    while(sum[0] < req && i<n){
        sum[0]+=a[i];
        i++;
    }
    ra = i;
    if(sum[0] >= req && sum[1]>=req && sum[2]>=req){
        cout << la << ' ' << ra << ' '<< lb << ' '<< rb << ' '<< lc << ' '<< rc;
        cout << nl;
        return;
    }

    i = 0; sum = vlli(3,0);
    lc = 1;
    while(sum[2] < req && i<n){ //c,a,b
        sum[2]+=c[i];
        i++;
    }
    rc = i;
    la = i+1;
    while(sum[0] < req && i<n){
        sum[0]+=a[i];
        i++;
    }
    ra = i;
    lb = i+1;
    while(sum[1] < req && i<n){
        sum[1]+=b[i];
        i++;
    }
    rb = i;
    if(sum[0] >= req && sum[1]>=req && sum[2]>=req){
        cout << la << ' ' << ra << ' '<< lb << ' '<< rb << ' '<< lc << ' '<< rc;
        cout << nl;
        return;
    }

    i = 0; sum = vlli(3,0);
    lc = 1;
    while(sum[2] < req && i<n){ //c,b,a
        sum[2]+=c[i];
        i++;
    }
    rc = i;
    lb = i+1;
    while(sum[1] < req && i<n){
        sum[1]+=b[i];
        i++;
    }
    rb = i;
    la = i+1;
    while(sum[0] < req && i<n){
        sum[0]+=a[i];
        i++;
    }
    ra = i;
    if(sum[0] >= req && sum[1]>=req && sum[2]>=req){
        cout << la << ' ' << ra << ' '<< lb << ' '<< rb << ' '<< lc << ' '<< rc;
        cout << nl;
        return;
    }
    cout << -1  << nl;
    return;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}