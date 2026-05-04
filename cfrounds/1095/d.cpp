#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin>> n;
    vector<int> a(n); rep(i, 0, n) cin >> a[i];
    int primero = 0, ultimo = n-1; //primero y ultimo fuera de posicion
    vector<int> b(n); rep(i, 0, n) b[i]= a[i];
    sort(all(b));
    int idx = 0;
    while(primero < n && a[primero] == b[primero]) primero++;
    idx = n-1;
    while(ultimo >= 0 && a[ultimo] == b[ultimo]) ultimo--;

    if(primero == n){ //si todos estan bien
        cout << "YES" << endl;
        return;
    }
    //cout << primero << ' ' << ultimo << ' ';
    bool sortedimp = true;
    bool sortedpar = true;
    vector<int> pares;
    vector<int> impares;
    rep(i,0,n){
        if(a[i]%2==0) pares.push_back(a[i]);
        else impares.push_back(a[i]);
    }
    rep(i, 1, pares.size()) if(pares[i]<pares[i-1]) sortedpar = false;
    rep(i, 1, impares.size()) if(impares[i] < impares[i-1]) sortedimp = false;
    int imp1 = 0, imp2 = 0, par1= 0, par2= 0;
    rep(i, 0, primero+1){
        if(b[i]%2 == 0) par1 = 1;
        else imp1 = 1;
    }
    for(int i = n-1; i>=ultimo; i--){
        if(b[i]%2 == 0) par2 = 1;
        else imp2 = 1;
    }
    if((sortedpar == true || (imp1||imp2)) && (sortedimp == true ||(par1 || par2))){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return;
}   


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}