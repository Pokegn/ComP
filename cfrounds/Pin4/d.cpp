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

vlli primos(30000, -1);
void llena(){
    vector<bool> vis(300000, 0);
    lli j = 0;
    forn(i, 2, 300000){
        if(vis[i] == 0){
            lli x = 1;
            primos[j] = i;
            //cout << j << ' ';
            j++;
            while(x*i<300000){
                vis[x*i] = true;
                x++;
            }
        }
    }
}


void solve(){
    lli n;
    //cout << primos[0];
    cin >> n;
    lli pri = 0;
    lli maxi = 1;
    vlli ans(n, -1);
    ans[1] = 1;
    forn(i, 2, n){ //la n

        forn(j, 1, 50){ //quiero ver si ans[i] esta desocupado
            bool flag = false;
            forn(k, 0, 100){ //con que primo estoy checando
                if((i^primos[k])<i && ans[(i^primos[k])] == j) flag = true;
            }
            if(flag == false){
                if(j<=maxi) ans[i] = j;

            } 
            
        }
        if(ans[i] == -1) ans[i] = maxi+1;
        maxi = max(maxi, ans[i]);

    }
    forn(i,1, n){
        cout << ans[i] << ' ';
    } 
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    llena();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}