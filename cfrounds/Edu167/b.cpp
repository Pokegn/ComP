#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long;
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
    string a,b; cin >> a>>b;
    int asz = a.length();
    int bsz = b.length(); //??
    vvi ans(asz+1, vi(bsz+1,0));

    forn(i, 0, asz+1) ans[i][0] = 0;
    forn(j, 0, bsz+1) ans[0][j] = 0;
    lli maxi = 0;
    vi maxans(bsz, 0);
    queue<pair<lli, lli>> metidas;

    forn(i, 1, asz+1){
        forn(j, 1, bsz+1){
            if(a[i-1] == b[j-1]){ //el mayor tamano de un substring de b que es subsequence de a acabando en el i de a y el j de b.
                ans[i][j] = maxans[j-1]+1;
                maxi = max((lli)ans[i][j], maxi);
                metidas.push({j, ans[i][j]});
            }
            else ans[i][j] = 0;
        }

        while(!metidas.empty()){
            int x = metidas.front().first;
            int d = metidas.front().second;

            metidas.pop();
            maxans[x] = max(d, maxans[x]);
        }
    }
    cout << asz+bsz-maxi << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}