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
    vector<vector<int>> a(n, vi(20));
    lli x;
    forn(i, 0, n){ //a[i][j] es el residuo j del elemento i
        cin >> x;
        forn(j, 0, 20){
            a[i][j] = x%2;
            x/=2;
        }
    }

    lli maxi = 1;
    lli curr = 0;
    forn(j, 0, 20){
        curr = 0;
        forn(i, 0, n){
            if(a[i][j] == 0){
                curr++;
            }
            else{
                maxi = max(curr+1, maxi);
                curr = 0;
            }
        }
        if(curr != n){
            maxi = max(curr+1, maxi);
        }
    }

    cout << maxi << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}