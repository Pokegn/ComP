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
    string a,b; cin >> a >> b;
    lli checo = 1;
    lli posi = 0, posp = 0;
    lli espaciosi = 0, espaciosp = 0;
    for(lli i=0; i<n; i++){
        
        if(checo == 1){
            espaciosp++;
            if(a[i]=='1') posi++;
            if(b[i]=='1'){
                posp++;
            } 
        }
        else{
            espaciosi++;
            if(a[i]=='1') posp++;
            if(b[i]=='1'){
                posi++;
            } 
        }
        checo*=-1;
    }

    if(posi>espaciosi || posp>espaciosp){
        cout << "NO" << nl;
    }
    else cout << "YES" << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}