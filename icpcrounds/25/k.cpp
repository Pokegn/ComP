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
    int n; cin >> n;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    
    int total = 0, obj = 0;
    for(int i=0; i<n; i++) total+=c[i];
    if(total%2==1){
        cout << -1 << endl;
        return;
    }
    obj = total/2;
    vector<vi> suma(total+1, vi(0,0)); //un ejemplo de suma posible

    vi posible(total+1, 0);
    posible[0] = 1;
    vi lista(1,0); //lista de los que se que se pueden

    //cout << "total " << total << endl;
    for(int i=0; i<n; i++){
        ll sz = lista.size();
        for(int j=0; j<sz; j++){
            //cout << lista[j] << ' ' << lista[j]+c[i] << endl;
            int x = lista[j];
            if(posible[x+c[i]] == 0){
                posible[x+c[i]] = 1;
                lista.push_back(x+c[i]);
                for(auto y: suma[x]){
                    suma[x+c[i]].push_back(y);
                }
                suma[x+c[i]].push_back(i);
            }
        }
    }
    
    // cout << "que" << endl;
    // return;
    if(posible[obj] == 0){
        cout << -1 << endl;
        return;
    }

    vlli ensuma(n, false);
    for(int i=0; i<suma[obj].size(); i++){
        ensuma[suma[obj][i]] = true;
    }
    vlli notsuma(0);
    for(int i=0; i<n; i++){
        if(ensuma[i] == false) notsuma.push_back(i);
    }

    ll sz1 = suma[obj].size();
    ll sz2 = notsuma.size();
    ll i1=0, i2=0;
    ll sa = 0, sb = 0;
    for(int i=0; i<n; i++){
        if(sa<=sb){
            cout << c[suma[obj][i1]] << ' ';
            sa+=c[suma[obj][i1]];
            i1++;
        }
        else{
            cout << c[notsuma[i2]] << ' ';
            sb+=c[notsuma[i2]];
            i2++;
        }
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}