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
    ll n; cin >> n;
    ll l,r; cin >> l >> r;
    vlli a(n); for(int i=0; i<n ; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    ll lp = 0, rp=0;
    //los de afuera del rango 
    ll izq = 0, der =0;
    ll li = 0, ri = n-1;
    for(int i=0; i<n; i++){
        if(a[i] <= l){
            der++;
            lp+=l-a[i];
            rp+=r-a[i];
            li = i+1;
            //cout << "der a " << a[i] << endl;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(a[i] >= r){
            izq++;
            lp+=a[i]-l;
            rp+=a[i]-r;
            //cout << "izq a " << a[i] << endl;
            ri = i-1;
        }
    }

    //el verdadero rango es de li a ri
    while(li<=ri){
        if(li == ri){
            if(der > izq){
                lp+=a[ri]-l;
                rp+=a[ri]-r;
                //cout << "izq aa " << a[ri] << endl;
                ri--;
                izq++;
            }
            if(der < izq){
                der++;
                lp+=l-a[li];
                rp+=r-a[li];
                //cout << "der aa " << a[li] << endl;
                li++;
            }
            break;
        }
        else{
            if(der > izq){
                lp+=a[ri]-l;
                rp+=a[ri]-r;
                //cout << "izq a " << a[ri] << endl;
                ri--;
                izq++;
            }
            else{
                der++;
                lp+=l-a[li];
                rp+=r-a[li];
                //cout << "der a " << a[li] << endl;
                li++;
            }
        }
    }

    cout << min(lp, rp) << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}