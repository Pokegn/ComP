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
lli ans = 0;
vlli temp;

void merg(lli l, lli m, lli r){
    lli li = l;
    lli ri = m+1;
    lli i=l;
    while(li <= m || ri <= r){
        if(li > m){
            temp[i] = a[ri];
            i++;
            ri++;
            continue;
        }
        if(ri > r){
            temp[i] = a[li];
            i++;
            li++;
            ans+=r-m;
            continue;
        }

        if(a[li]<a[ri]){
            temp[i] = a[li];
            i++;
            li++;
            ans+=ri-m-1;
        }
        else{
            temp[i] = a[ri];
            i++;
            ri++;
            ans+=m+1-li;
        }
    }

    forn(j, l, r+1){
        a[j] = temp[j];
    }
}

void mergesort(lli l, lli r){
    if(l == r) return;
    lli m = (l+r)/2;
    mergesort(l, m);
    mergesort(m+1,r);
    merg(l, m, r);
}

void solve(){
    ans = 0;
    lli n; cin >> n;
    vlli b(n);
    temp.assign(n, 0);
    a.assign(n, 0);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];


    map<lli, lli> locasion1;
    map<lli, lli> locasion2;
    forn(i, 0, n){
        locasion1.insert({a[i], i+1}); //donde esta a[i]
        locasion2.insert({b[i], i+1}); //donde esta b[i]   
    }

    forn(i, 0, n){
        if(locasion2[a[i]] == 0){
            cout << "NO" << nl;
            return;
        }
    }


    mergesort(0, n-1);
    //cout << ans << ' ';
    forn(i, 0, n) a[i] = b[i];
    mergesort(0, n-1);
    //cout << ans << nl;
    ans/=2;
    if(ans%2 == 0) cout << "YES" << nl;
    else cout << "NO" << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}