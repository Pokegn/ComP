#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define fi first
#define se second
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,m; cin >> n >> m;
    ll d,e; cin >> d >> e;
    vector<vlli> fplay(n+1, vlli(m+1, 0));

    vector<vlli> playtime(n+1, vlli(m+1, 0));
    vector<ll> playing(n+1, -1);
    vector<ll> playstart(n+1, -1);
    ll s,k,t;
    for(int i=0; i<e; i++){
        cin >> s >> k >> t;
        if(t == 0){
            playtime[k][t] += s-playstart[k];
            playing[k] = -1;
            playstart[k] = -1;
        }
        else{
            fplay[k][t] = max(d+1-s, fplay[k][t]);
            playstart[k] = s;
            playing[k] = t;
        }
    }

    for(int i=1; i<n+1; i++){
        if(playing[i]!=-1){
            playtime[i][playing[i]] += d-playstart[i];
        }
    }

    //ahora quiero para cada toy, el conjunto de kids tal que no hay un niño que tenga un playtime y fplay mas alto al mismo tiempo




}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}