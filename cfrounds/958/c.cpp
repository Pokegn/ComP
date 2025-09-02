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
    lli pot = 1;
    lli ori = n;
    lli ans = 0;
    vlli anss = {n};
    while(n>0){
        if(n%2 ==1){
            ans++;
            anss.push_back(ori-pot);
        } 
        n/=2;
        pot*=2;
    }
    if(ans!=1) ans++;
    cout << ans<< nl;

    n = ori;
    if(ans==1){
        cout << n << nl;
        return;
    }


    rof(i, ans-1, 0){
        cout << anss[i] << ' ';
    }
        cout << nl;
        


}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}