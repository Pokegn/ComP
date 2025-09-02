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
    lli l,r; cin >> l >>r;

    vlli a(n+1,0);
    forn(i, 1, n+1 )cin >> a[i];

    vlli suma(n+1,0);
    forn(i, 1, n+1) suma[i] = suma[i-1]+a[i];

    lli sumarango = suma[r]-suma[l-1];

    priority_queue<lli> lefti, righti;
    forn(i, l, r+1){
        lefti.push(a[i]);
        righti.push(a[i]);
    }

    lli ansl = sumarango;
    lli temp = sumarango;
    minheap<lli> left;
    forn(i, 1, l){
        left.push(a[i]);
    }
    lli x,y;
    forn(i, 1, l){
        if(!left.empty() && !lefti.empty()){
            x = left.top();
            y = lefti.top();
            temp = temp+x-y;
            ansl = min(ansl, temp);
            left.pop();
            lefti.pop();
        } 
    }

    temp = sumarango;
    minheap<lli> right;
    forn(i, r+1, n+1){
        right.push(a[i]);
    }

    forn(i, r+1, n+1){
        if(!righti.empty() && !right.empty()){
            x = right.top();
            y = righti.top();
            temp = temp+x-y;
            ansl = min(ansl, temp);
            right.pop();
            righti.pop();
        } 
    }

    cout << ansl << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}