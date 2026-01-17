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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n, e; cin >> n >> e;
    ll t;
    map<ll, ll> a; //congruencia de t y i
    pair<ll, ll> primer = {-1,-1};
    vector<ll> xd(1e7);
    for(ll i = 1; i<3*n+4; i++){
        t+=e; 
        xd[i] = t;
        if(a[t%n] != 0 && primer == pair<ll,ll>{-1,-1}){
            primer = {a[t%n], i};
        }   
        a[t%n] = i;
        if(t%n == 0) e++;
        else e--;
        if(e==0){
            cout << t << nl;
            return;
        }
    }

    if(primer.first == primer.second){
        cout << "infinity" << nl;
        return;
    }

    ll ciclo = primer.second - primer.first;
    if(ciclo<0) ciclo*=-1;
    ll baja = xd[primer.second] - xd[primer.first];

    ll loops = xd[primer.second]/baja;
    
    e = xd[primer.second]/loops;
    

    

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}