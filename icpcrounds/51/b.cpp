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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

struct mamamierda {
    ll c2, c1, u1, u2;

    bool operator<(const mamamierda &other) const{
        if(c1 != other.c1){
            return c1 > other.c1;
        }
        if(u1 != other.u1){
            return u1 < other.u1;
        }
        if(c2 != other.c2){
            return c2 > other.c2;
        }
        return u2 < other.u2;
    }
};

void solve(){
    int n; cin >> n;
    ll x,y; cin >> x >> y;
    string stst; cin >> stst;
    vector<ll> s(n);
    rep(i, 0, n) s[i] = (ll)(stst[i]-'0');

    vector<ll> caben0(n), caben1(n); //mousequerramienta misteriosa
    vector<ll> hay0(n), hay1(n);
    ll curr0 = 0, curr1 = 0, tot0 = 0, tot1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 0){
            curr0++;
            tot0++;
        }
        if(s[i] == 1){
            curr1++;
            tot1++;
        }
        if(s[i] == 2){
            curr1++;
            curr0++;
        }
        caben0[i] = curr0;
        caben1[i] = curr1;
        hay0[i] = tot0;
        hay1[i] = tot1;
    }

    ll total = x+y;
    ll B = total/n; // cantidad de bloques
    
    vector<mamamierda> posibles;

    //d = derecha por bloque, u = arriba por bloque
    for(ll d = 0; d<=n; d++){
        ll u = n-d;
        if(d < tot0 || u < tot1) continue;
        ll rx, ry;
        rx = x - B*d;
        ry = y - B*u;
        if(rx < 0 || ry < 0 || rx > n || ry > n) continue;
        if(rx > d || ry > u) continue;
        ll i = (x+y)%n; // cuantos me faltaron de poner
        if((rx+ry) != i) continue; //checar
        
        //si no caben rx ceros entre 0 y i-1 lloro
        if(i > 0 && caben0[i-1] < rx) continue;
        if(i > 0 && caben1[i-1] < ry) continue;
        
        mamamierda add;
        
        if(i == 0) add.c1 = 0;
        else add.c1 = rx-hay0[i-1];
        
        if(i == 0) add.u1 = 0;
        else add.u1 = ry-hay1[i-1]; 
        
        add.c2 = d - add.c1 - tot0; 
        
        add.u2 = u - add.u1 - tot1; 
        
        
        //cout << "hoy llegue " << d << ' ';
        if(add.c1 < 0 || add.c2 < 0 || add.u1 < 0 || add.u2 < 0) continue;
        if(add.u1 == 0){
            add.u1 += add.u2;
            add.u2 = 0;
            add.c1 += add.c2;
            add.c2 = 0;
        }
        //cout << "datos " << i << ' ' << add.c1 << ' ' << add.u1 << ' ' << add.c2 << ' ' << add.u2 << endl;
        posibles.push_back(add);
    }

    sort(all(posibles));
    if(posibles.size() == 0){
        cout << -1 << endl;
        return;
    }

    mamamierda god = posibles[0];
    //for(auto god: posibles){
    for(int i = 0; i < n; i++){
        if(s[i] == 1){
            cout << 1; continue;
        }
        if(s[i] == 0){
            cout << 0; continue;
        }
        if(god.c1 > 0){
            cout << 0;
            god.c1--;
            continue;
        }
        if(god.u1 > 0){
            cout << 1;
            god.u1--;
            continue;
        }    
        if(god.c2 > 0){
            cout << 0;
            god.c2--;
            continue;
        }     
        if(god.u2 > 0){
            cout << 1;
            god.u2--;
            continue;
        }     
    }
    //     cout << ' ';
    // }
    //cout << endl;
    cout << endl; 
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}