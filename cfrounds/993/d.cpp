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

void solve(){
    lli n; cin >> n;
    vlli a(n); forn(i, 0, n) cin >> a[i];

    vector<bool> aparece(n+1, false);
    forn(i, 0, n) aparece[a[i]] = true;

    queue<lli> noaparece;
    forn(i, 1, n+1) if(aparece[i] == false) noaparece.push(i);

    vlli b(n);
    vector<bool> tomado(n+1, false);
    forn(i, 0, n){
        if(tomado[a[i]]){
            b[i] = noaparece.front();
            noaparece.pop();
        }
        else{
            b[i] = a[i];
            tomado[a[i]] = true;
        } 
    }

    forn(i, 0, n){
        cout << b[i] << ' ';
        
    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}