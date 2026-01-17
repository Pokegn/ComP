#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n,x; cin >> n;
    x = 64; //la potencia xd
    vector<vlli> a(21, vlli(0));
    ll last = 1e10;
    ll cost = 0;
    cout << 250000 << endl;

    for(int i=250000; i>=1; i--){
        ll i2 = i;
        ll j = 0;
        while(i2%x == 0){
            j++;
            i2/=x;
        }
        a[j].push_back(i);
    }
    ll impresiones = 0;

    for(int i=0; i<4; i++){
        ll xd= 1;
        for(int j=0; j<i; j++) xd*=x;

        for(int z = 1; z<x; z++){
            for(int j=0; j<a[i].size(); j++){
                if(((a[i][j]/xd)%x)!=z) continue;
                ll sumando = xd;
                //ll sumando = xd*(x-(a[i][j]/xd)%x);
                cost+=sumando;

                cout << a[i][j] << ' ' << xd << endl;
                impresiones++;
            }
        }
        
    }
    //cout << impresiones << endl;
    //ll otrocost = (x-1)*(ll)(floor(log(250000)/log(x)));
    // cout << otrocost << endl;
    // cout << cost << endl;
    // cout << cost + otrocost*1000;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    while(t--) solve();
    return 0;
}