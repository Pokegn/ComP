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

string lltos(ll n, ll sizee){
    string s = "";
    for(int i=0; i< sizee; i++){
        if(n%2 == 1){
            s+='1';
        }
        else s+='0';
        n/=2;
    }
    reverse(all(s));
    return (s);
}

void solve(){
    ll n; cin >> n;

    vector<string> pos;
    for(ll i = 0; i<(1<<n); i++){
        string s = lltos(i,n);
        int unos = 0;
        rep(j, 0, n) if(s[j] == '1') unos++;
        if(unos == 3)
        pos.push_back(lltos(i, n));
    }
    string best;
    ll ans = 100000000;
    for(auto s: pos){
        // cout << s << endl;
        ll count = 0;
        rep(l, 0, n){
            rep(r, l, n){
                ll pot = 1;
                ll curr = 0;

                for(int i = r; i>=l; i--){
                    curr += (ll)(s[i]-'0')*pot;
                    pot*=2;
                }
                if(curr%3 == 0) count++;
            }
        }
        if(count <= ans){
            best = s;
            ans = count;
        }
    }
    cout << best << ' ' << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}