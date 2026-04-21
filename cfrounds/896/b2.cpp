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
    //cout << s << ' ';
    vector<ll> difs(n);
    rep(i, 0, n) difs[i] = s-a[i];
    vector<int> signo(n);
    rep(i, 0, n) signo[i] = (difs[i] < 0 ? -1 : 1);
    rep(i, 0, n) difs[i] = abs(difs[i]);

    vector<int> count(40, 0);
    vector<int> DT(40, 0);//cuantos tengo o me faltan de 2^x - 0 o 2^x+1 - 2^x
    vector<int> DS(40, 0);
    rep(i, 0, n){
        if(difs[i] == 0) continue;
        else if(pow2_lb(difs[i]) == difs[i]){
            if(signo[i] == 1)
            DT[msb(difs[i])] ++;
            else DS[msb(difs[i])]++;
        } 
        else{
            ll grande = pow2_lb(difs[i]);
            ll chico = grande - difs[i];
            if(pow2_lb(chico) != chico){
                cout << "no" << endl;
                return;
            }
            count[msb(grande)] += signo[i];
            count[msb(chico)] -= signo[i];
        }
    }
    //rep(i, 0, 5) cout << i << ' ' << count[i] << ' ' << DS[i] << ' ' << DT[i] << endl;
    //cout << endl;

    swap(DT, DS);
    for(int i = 31; i>=0; i--){
        //cout << i << ' ' << count[i+1] << ' ' << count[i] << ' ' << DS[i] << ' ' << DT[i] << endl;
        int coso = DS[i]-DT[i]+count[i+1];
        count[i] += 2*coso-DS[i]+DT[i];
        count[i+1] += -coso+DS[i]-DT[i];
        //cout << i << ' ' << count[i+1] << ' ' << count[i] << ' ' << DS[i] << ' ' << DT[i] << endl;
        //cout << coso << endl;

        if(coso > DS[i] || coso < -DT[i]){
            cout << "no" << endl;
            return;
        }
    }
    if(count[0] == 0){
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}