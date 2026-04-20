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
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    ll s = 0; rep(i, 0, n) s+=a[i];
    if(s%n!=0){
        cout << "no" << endl; return;
    }
    s/=n;
    vector<ll> difs(n);
    rep(i, 0, n) difs[i] = s-a[i];
    vector<int> signo(n);
    rep(i, 0, n) signo[i] = (difs[i] < 0 ? -1 : 1);
    rep(i, 0, n) difs[i] = abs(difs[i]);

    vector<int> tipo(n);
    // vector<ll> dar;
    // vector<ll> recibir;
    // vector<pair<ll, ll>> maybedar;
    // vector<pair<ll, ll>> mayberecibir;
    vector<int> count(40, 0);
    vector<int> maybecount(40, 0);//cuantos tengo o me faltan de 2^x - 0 o 2^x+1 - 2^x
    rep(i, 0, n){
        if(difs[i] == 0) tipo[i] = 1;
        else if(pow2_lb(difs[i]) == difs[i]){
            tipo[i] = 2;
            pair<ll, ll> p1, p2;
            p1 = {difs[i], 2*difs[i]}; p2 = {0,difs[i]};
            maybecount[msb(difs[i])] += signo[i]; 
            // if(signo[i] == 1){
            //     maybedar.push_back(p2);
            //     mayberecibir.push_back(p1);
            // }
            // else{
            //     maybedar.push_back(p1);
            //     mayberecibir.push_back(p2);
            // }
        } 
        else{
            tipo[i] = 3;
            ll grande = pow2_lb(difs[i]);
            ll chico = grande - pow2_lb(difs[i]);
            if(pow2_lb(chico) != chico){
                cout << "no" << endl;
                return;
            }
            count[msb(grande)] += signo[i];
            count[msb(chico)] -= signo[i];
            // if(signo[i] == -1) swap(grande, chico);
            // recibir.push_back(grande);
            // dar.push_back(chico);
        }
    }

    rep(i, 0, 40){
        while(count[i]!=0){
            if(count[i] < 0){
                count[i]++;
                
            }
            else{

            }
        }
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}