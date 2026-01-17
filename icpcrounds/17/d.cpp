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

ll fexp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n,d; cin >> n >> d;
    ll x;
    vector<vlli> a(10, vlli(0));
    vector<vlli> a5(5, vlli(0));
    //ll x;
    for(int i=0; i<n; i++){
        cin >> x;
        a[x%10].push_back(x);
    }

    if(d%2 == 1){
        for(int i=0; i<10; i++){
            if(i%2==1) continue;
            a[i] = vlli(0); //lo vacio XD
        }
    }

    for(int i=0; i<10; i++){
        sort(a[i].begin(), a[i].end());
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<a[i].size(); j++){
            if(i%2==0 && d%2!=0) continue;
            a5[i%5].push_back(a[i][j]);
        }
    }

    vlli pick(10);
    vlli remove(10, 0);
    vlli most(10);
    most[0] = 0;
    most[1] = 0;
    most[2] = 3;
    most[3] = 3;
    most[4] = 1;
    most[5] = 0;
    most[6] = 0;
    most[7] = 3;
    most[8] = 3;
    most[9] = 1;

    if(d == 0){
        for(int i=0; i<10; i++){
            if(a[0].size() == 0){
                if(a[5].size() == 0){
                    cout << -1 << endl;
                    return;
                }
                if(a[2].size()+a[4].size()+a[6].size()+a[8].size() == 0){
                    cout << -1 << endl;
                    return;
                }
            }
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<a[i].size(); j++){
                cout << a[i][j] << ' ';
            }
        }
        return;
    }
    if(d == 5){
        if(a[5].size() == 0){
            cout << -1 << endl;
            return;
        }
        for(int i=0; i<10; i++){
            if(i%2==0) continue;
            for(int j=0; j<a[i].size(); j++){
                cout << a[i][j] << ' ';
            }
        }
        return;
    }

    a5[0] = vlli(0);
    a[0] = vlli(0);
    a[5] = vlli(0);

    ll all = 1;
    for(int i=0; i<5; i++){
        for(int j=0; j<a5.size(); j++){
            all*=a5[i][j];
            all%=10;
        }
    }

    ll pares = 0;
    for(int i=0; i<5; i+=2){
        pares+=a[i].size();
    }

    __int128_t divido = 1e31;
    vlli nochoose;
    while (true) { //iteramos 
        __int128_t prod = 1;
        
        for(int i=0; i<10; i+=2){
            if(remove[i]>a[i].size()) remove[i] = a[i].size();
        }

        
        int pos = 0;
        bool valio = false;
        for(int i=0; i<10; i++){
            if(remove[i]>a[i].size()){
                valio = true;
            }
        }
        
        if(d%2){
            if(remove[0]+remove[2]+remove[4]+remove[6]+remove[8] == pares) valio = true;
        }
        
        if(!valio){
            for(int i=0; i<10;  i++){
                for(int j=0; j<remove[i]; j++){
                    prod*=a[i][j];
                }
            }

            ll residuo;
            if(prod%5 == 1) residuo = 1;
            if(prod%5 == 2) residuo = 3;
            if(prod%5 == 3) residuo = 2;
            if(prod%5 == 4) residuo = 4;

            if((all*residuo)%5 == d%5){
                if(d%2==0){
                    if(prod<divido){
                        divido = prod;
                        nochoose = remove;
                    }
                }
            }
        }
        
        while (pos < 10) {
            if (remove[pos] < most[pos]) {
                remove[pos]++;
                break;
            } else {
                remove[pos] = 0;
                pos++;
            }
        }
        if (pos == 5) break;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}