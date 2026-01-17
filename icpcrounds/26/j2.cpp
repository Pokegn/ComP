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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n,x; cin >> n >> x;
    vlli a(n); for(ll i = 0; i<n; i++) cin >> a[i];

    map<ll, ll> m;
    for(ll i=0; i<n; i++) m[a[i]]++;

    ll mitad = -1;
    if(x%2 == 0) mitad = x/2;

    vlli f1(0), f2(0), f3(0); //f1 es con par primero, f2 es sin par primero, f3 es con par segundo
    map<ll, ll> vis;
    for(ll i=0; i<n; i++){
        if(2*a[i] == x) continue;
        if(vis[a[i]] == 2) continue;
        vis[a[i]] = 2;
        vis[x-a[i]] = 2;
        if(m[x-a[i]] > 0){
            for(ll j = 0; j<m[a[i]]; j++) f1.push_back(a[i]);
            for(ll j = 0; j<m[x-a[i]]; j++) f3.push_back(x-a[i]);
        }
        else for(ll j = 0; j<m[a[i]]; j++) f2.push_back(a[i]);
    }
    vlli ans(0);
    sort(f1.begin(), f1.end());
    sort(f3.begin(), f3.end());
    for(ll i=0; i<f1.size(); i++) ans.push_back(f1[i]);
    for(ll i=0; i<f2.size(); i++) ans.push_back(f2[i]);
    for(ll i=0; i<f3.size(); i++) ans.push_back(f3[i]);    
    
    for(ll i=0; i<n; i++){ //si solo son de dos tipos que suman x efe
        if(a[i] == mitad) continue;   
        if(m[a[i]]+m[x-a[i]] == n && m[x-a[i]]>0){
            cout << "*" << endl;
            return;
        }
    }
    
    if(x%2 == 0){
        if(n - 2*m[mitad] < -1){
            cout << "*" << endl;
            return;
        }
    } //hay al menos tres tipos
    
    ll casoraro = 0;
    if(x%2 == 0){
        for(ll i=0; i<n; i++){
            if(2*a[i] == x) continue;
            if(m[a[i]]+m[x-a[i]]+m[mitad] == n){
                casoraro = 1;
            }
            if(m[a[i]] == n){
                for(ll j=0; j<n; j++){
                    cout << a[j] << ' ';
                }
                cout << endl;
                return;
            }
            if(m[a[i]]+m[x-a[i]] == x){
                cout << "*" << endl;
                return;
            }
        }
        if(n-2*m[mitad] == -1) casoraro = 0;
    }

    vlli medios(ans.size()+1, 0);
    ll curr = 0;
    ll total = m[mitad];
    for(ll i=0; i<medios.size(); i++){
        if(curr < total){
            medios[i] = 1;
            curr++;
        }
    }

    if(casoraro == 1){ //todos son de 3 tipos, uno es medios
        ll idx = -1;
        for(ll i=1; i<ans.size(); i++){
            if(ans[i]!=ans[i-1]) idx = i; 
        }

        if(medios[idx] == 0){
            medios[0] = 0;
            medios[idx] = 1;
        }
    }

    for(ll i=0; i<ans.size(); i++){
        if(medios[i] == 1) cout << mitad << ' ';
        cout << ans[i] << ' ';
    }
    if(medios[ans.size()] == 1) cout << mitad << ' ';
    cout << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}