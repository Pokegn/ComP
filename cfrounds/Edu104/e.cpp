#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;

    vector<ll> a1(n1), a2(n2), a3(n3), a4(n4);
    rep(i, 0, n1) cin >> a1[i];
    rep(i, 0, n2) cin >> a2[i];
    rep(i, 0, n3) cin >> a3[i];
    rep(i, 0, n4) cin >> a4[i];

    ll m1, m2, m3;
    cin >> m1;
    vector<set<ll>> no12(n2);
    rep(i, 0, m1){
        ll u,v; cin >> u >> v; u--, v--;
        no12[v].insert(u);
    }
    cin >> m2;
    vector<set<ll>> no23(n3);
    rep(i, 0, m2){
        ll u,v; cin >> u >> v; u--, v--;
        no23[v].insert(u);
    }
    cin >> m3;
    vector<set<ll>> no34(n4);
    rep(i, 0, m3){
        ll u,v; cin >> u >> v; u--, v--;
        no34[v].insert(u);
    }

    vector<pair<ll, ll>> a1ord(n1), a2ord(n2), a3ord(n3), a4ord(n4);

    vector<ll> cost1(n1), cost2(n2), cost3(n3), cost4(n4); //mincost de comprar ese
    rep(i, 0, n1){
        cost1[i] = a1[i];
    }
    rep(i, 0, n1) a1ord[i] = {cost1[i], i};
    sort(all(a1ord));

    rep(i, 0, n2){ //quiero el menor indice idx tal que a1ord[idx] no esta en el set
        ll idx = 0;
        while(idx < a1ord.size() && no12[i].count(a1ord[idx].second)) idx++;
        if(no12[i].size() == n1){
            cost2[i] = 500000000;
        }
        else{
            cost2[i] = a2[i] + cost1[a1ord[idx].second];
        }
    }

    rep(i, 0, n2) a2ord[i] = {cost2[i], i};
    sort(all(a2ord));
    // cout << "costos ";
    // for(auto x: cost2) cout <<x << ' ';
    rep(i, 0, n3){ //quiero el menor indice idx tal que a1ord[idx] no esta en el set
        ll idx = 0;
        while(idx < a2ord.size() && no23[i].count(a2ord[idx].second)) idx++;
        if(no23[i].size() == n2){
            cost3[i] = 500000000;
        }
        else{
            cost3[i] = a3[i] + cost2[a2ord[idx].second];
        }
    }
    rep(i, 0, n3) a3ord[i] = {cost3[i], i};
    sort(all(a3ord));
    //return;
    rep(i, 0, n4){ //quiero el menor indice idx tal que a1ord[idx] no esta en el set
        ll idx = 0;
        while(idx < a3ord.size() && no34[i].count(a3ord[idx].second)) idx++;
        if(no34[i].size() == n3){
            cost4[i] = 500000000;
        }
        else{
            cost4[i] = a4[i] + cost3[a3ord[idx].second];
        }
    }

    rep(i, 0, n4) a4ord[i] = {cost4[i], i};
    sort(all(a4ord));

    ll ans = 1000000000;
    for(auto x: cost4) ans = min(ans, x);
    if(ans >= 500000000) cout << -1 << endl;
    else cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}