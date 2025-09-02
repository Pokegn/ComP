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
    lli n,m,k;
    cin >> n >> m >> k;
    vlli a(n);
    forn(i,0 ,n) a[i] = i+1;
    vlli ceros;
    lli temp;
    forn(i, 0, n){
        if(a[i]<=m) a[i]*=-1;
        else if(a[i]<k){
            ceros.push_back(a[i]);
            a[i]=0;
        } 
    }
    sort(a.begin(), a.end());
    lli j = 0;
    forn(i, 0, n){
        if(a[n-1-i] < 0) a[n-1-i]*=-1;
        if(a[n-1-i] == 0){
            a[n-1-i] = ceros[j];
            j++;
        }
        cout << a[n-1-i] << ' ';
    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}