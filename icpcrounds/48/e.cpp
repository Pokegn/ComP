#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ld ret[100][100][100];

ld ans(int a, int b, int c){
    vector<int> xd = {a,b,c}; sort(all(xd));
    a = xd[0], b = xd[1], c = xd[2];
    if(ret[a][b][c]!=0) return ret[a][b][c];
    if(a == 0){
        ret[a][b][c] = 3.0*min(b,c);
        return ret[a][b][c];
    }
    else{
        ret[a][b][c] = 1.5 + 0.5*ans(a-1, b+1, c) + 0.5*ans(a-1, b, c+1);
        return ret[a][b][c];
    }
}

void solve(){
    rep(i, 0, 100) rep(j, 0, 100) rep(k, 0, 100) ret[i][j][k] = 0;
    int n; cin >> n;
    string s; cin >> s;
    vector<ld> count(3, 0);
    map<char, int> m;
    m['r'] = 0;
    m['g'] = 1;
    m['b'] = 2;
    rep(i, 0, n){
        count[m[s[i]]]++;
    }
    cout << fixed << setprecision(10) << ans(count[0], count[1], count[2]);
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    
    //cin >> t;
    while(t--) solve();
    return 0;
}