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
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];

    vector<ll> big; 
    vector<ll> smol;
    big.push_back(0); smol.push_back(0);
    rep(i, 1, n){
        auto sz = big.size();
        if(sz%2 == 1){ //sigue uno chikito
            if(a[big[sz-1]] <= a[i]) big[sz-1] = i;
            else{
                big.push_back(i);
                //cout << "XD";
            }
        }
        else{
            if(a[big[sz-1]] >= a[i]) big[sz-1] = i;
            else{
                big.push_back(i);
                //                cout << "XD";

            }
        }
    }
    rep(i, 1, n){
        auto sz = smol.size();
        if(sz%2 == 1){
            if(a[smol[sz-1]] >= a[i]) smol[sz-1] = i;
            else{
                smol.push_back(i);
            }
        }
        else{
            if(a[smol[sz-1]] <= a[i]) smol[sz-1] = i;
            else{
                smol.push_back(i);
            }
        }
    }

    int sz = max(smol.size(), big.size());
    if(sz<3){
        cout << 0 << endl;
        return;
    }
    cout << sz << endl;
    if(smol.size() > big.size()){
        for(auto x: smol) cout << x << ' ';
        cout << endl;
    }
    else{
        for(auto x: big) cout << x << ' ';
        cout << endl;
    }
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}