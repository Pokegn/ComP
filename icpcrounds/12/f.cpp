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
    ll n;cin>>n;
    vlli a(n); for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vlli orig(n); for(int i=0; i<n; i++) orig[i] = a[i];
    ll pot = 0;
    ll temp = n;
    while(temp>1){
        pot++;
        temp/=2;
    }
    
    vvlli bits(pot+1, vlli(n));
    for(int p = 0; p<pot+1; p++){
        for(int i=0; i<n; i++){
            bits[p][i] = a[i]%2;
            a[i]/=2;
            //cout << bits[p][i] << ' ';
        }
        //cout << nl;
    }
    for(int i=0; i<n; i++) a[i] = orig[i];

    ll x = 0;
    ll ans =0;
    vector<vector<ll>> lista(n); //lista con 1>>algo
    for(int p = pot; p>=0; p--){ //para cada bit
        vlli ceros = vlli(n,0);
        vlli unos = vlli(n,0);
        vlli inv0 = vlli(n,0); //los 10s
        vlli inv1 = vlli(n,0); //los 01s
        for(int i=0; i<n; i++){
            ll j = a[i]>>(p+1);
            //cout << p << ' ' << a[i] << ' ' << j << ' ' << bits[p][i] << ' ' << nl;
            if(bits[p][i] == 0){
                ceros[j]++;
                inv0[j]+=unos[j];
            }
            else{
                unos[j]++;
                inv1[j]+=ceros[j];
            }
        }
        //cout << nl;
        ll inversions0 = 0, inversions1 = 0;
        for(int i=0; i<n; i++){
            inversions0+=inv0[i];
            inversions1+=inv1[i];
        }
        if(inversions0 > inversions1){
            ll suma = 1<<pot;
            x+=suma;
        }
        ans+=min(inversions0, inversions1);
    }

    if(x != 0) ans++;
    cout << ans << nl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}