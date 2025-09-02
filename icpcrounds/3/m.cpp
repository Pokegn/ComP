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
    int n,m; cin >> n >> m;
    vector<vector<char>> a(n+2, vector<char> (m+2, '.'));
    forn(i, 1, n+1){
        forn(j, 1, m+1){
            cin >> a[i][j];
        }
    }

    forn(i, 1, n+1){
        forn(j, 1, m+1){
            if(a[i][j] == 'B'){
                if(a[i][j-1] == 'W' && a[i-1][j-1] == 'W'){

                }
                else if(a[i][j-1] == 'W'){
                    
                }
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    lli t; cin >> t;
    while(t--)
    solve();
    return 0;
}