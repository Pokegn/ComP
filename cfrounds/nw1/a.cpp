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
    int n; cin >> n;
    string s; cin >> s;
    lli r = n;
    lli l = 1;
    vi a(n+1);
    rof(i, n-2, 0){
        //cout << s[i] << ' ';
        if(s[i] == '<'){
            a[i+1] = l;
            l++;
        }
        else{
            a[i+1] = r;
            r--;
        }
    }
    a[0] = l;
    forn(i, 0, n) cout << a[i] << ' ';
    cout << nl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}