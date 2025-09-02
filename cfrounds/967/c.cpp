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

int parent(int i, int x){
    cout << "? " << i << ' ' << x << endl;
    int ans;
    cin >> ans;
    if(ans == i) return x;
    else return parent(i, ans);
}

void solve(){
    int n; cin >> n;
    vi parents(n+1);
    forn(i, 2, n+1) parents[i] = parent(i, 1);
    cout << "! ";
    forn(i, 2, n+1){
        cout << i << ' ' << parents[i] << " ";
    }
}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}