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

    vector<pair<ll, ll>> big(n); //tamano, val
    vector<pair<ll, ll>> smol(n);//tamano, val
    big[n-1] = smol[n-1] = {1, a[n-1]};
    for(int i = n-2; i>=0; i--){
        if(a[i] < a[i+1]){
            smol[i] = {big[i+1].first+1, a[i]};
            big[i] = big[i+1];
            continue;
        }
        if(a[i] > a[i+1]){
            smol[i] = smol[i+1];
            big[i] = {smol[i+1].first+1, a[i]};
            continue;
        }
    }
    int lastbig = true; //el ultimo q meti es big
    if(smol[0].first > big[0].first) lastbig = false;
    vector<ll> ans; ans.push_back(0);
    // if(lastbig) cout << "XD";

    rep(i, 1, n){
        auto xdd = ans.back();
        if(lastbig){
            auto xd = big[xdd];
            if(smol[i].second < xd.second && smol[i].first == xd.first-1){
                ans.push_back(i);
            }
        }
        else{
            auto xd = smol[xdd];
            if(big[i].second > xd.second && big[i].first == xd.first-1){
                ans.push_back(i);
            }
        }
        lastbig = !lastbig;
    }

    // rep(i, 0, n){
    //     cout << big[i].first << ' ' << big[i].second << ' ' << smol[i].first << ' ' << smol[i].second << endl;
    // }
    if(ans.size() < 3){
        cout << 0 << endl;
        return;
    }
    cout << ans.size() << endl;
    for(auto xxx: ans) cout << xxx << ' ';
    cout << endl;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}