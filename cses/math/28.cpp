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
#define ld long double
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    int a,b; cin >> a >> b;
    vector<ld> probs(6*n+1, 0);
    probs[0] = 1;
    for(int i=1; i<=n; i++){
        vector<ld> temp(6*n+1, 0);
        for(int j=0; j<6*n+1; j++){
            for(int dif = 1; dif<=6; dif++) if(j-dif>=0) temp[j] += probs[j-dif]/6;
        }
        probs = temp;
    }

    ld ans=0;
    for(int i=a; i<=b; i++){
        ans+=probs[i];
    }
    cout << fixed << setprecision(6) << ans << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}