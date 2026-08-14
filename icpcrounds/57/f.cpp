#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
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
const ll INF = 1e12;

vector<ll> to_vec(ll n, ll b){
    vector<ll> ret(0);
    ll maxpot = 1;
    while(maxpot <= n/b) maxpot *= b;
    while(maxpot>0){
        ret.push_back(n/maxpot);
        n -= maxpot*(n/maxpot);
        maxpot/=b;
    }
    return ret;
}

vector<vector<vector<ll>>> ans2(11, vector<vector<ll>>(65, vector<ll>((1ll<<11), 0)));
//dimensiones son la cantidad de digitos y el xor de los numeros
void fillxor(ll base){
    ans2[base][0][0] = 1;
    for(ll k = 1; k<(1ll<<(base)); k*=2){
        ans2[base][1][k] = 1; //el digito i para i = 1, 2, ..., base
    }
    ll i = 2;
    rep(i, 2, 65){
        rep(j, 0, (1ll<<(base))){
            for(ll k = 1; k<(1ll<<(base)); k*=2){
                //if(base == 10 && j == k) cout << k << ' ';
                ans2[base][i][j] += ans2[base][i-1][(j^k)];
            }
        }
    }
    return;
}

ll ans(vector<ll> n, ll base){   
    ll ret = 0;
    ll accumxor = 0;
    for(ll ceros = 1; ceros < n.size(); ceros++){ //leading zeroes
        for(ll dig = 1; dig < base; dig++) ret += ans2[base][n.size()-ceros-1][(1ll<<dig)];
        //cout << ret << ' ';
    }
    for(ll j = 1; j < n[0]; j++){ //el primer digito
        ret += ans2[base][n.size()-1][accumxor^(1ll<<j)];
        //cout << ret << ' ';
    }
    accumxor^=(1ll<<(n[0]));
    for(ll i = 1; i < n.size(); i++){ //caso general
        for(ll j = 0; j < n[i]; j++){
            ret += ans2[base][n.size()-i-1][accumxor^(1ll<<(j))];
            //if(ans2[base][n.size()-i-1][accumxor^(1ll<<(j))] > 0) cout << i << ' ' << j << ' ' << n.size()-i-1 << ' ' <<(accumxor^(1ll<<(j))) << ' ' << ans2[base][n.size()-i-1][accumxor^(1ll<<(j))] << endl;
        } //ans2[2][3][1] = 4???
        accumxor ^= (1ll<<(n[i]));
        //cout << ret << ' ';
    }
    if(accumxor == 0){
        ret++;
    }
    // cout << accumxor << ' ';
    return ret;

}

void solve(){
    ll q; cin >> q;
    for(ll i = 2; i<=10; i++) fillxor(i);
    while(q--){
        ll b; ll l,r;
        cin >> b >> l >> r;
        auto no = to_vec(l-1, b);
        auto yes = to_vec(r, b);
        //cout << "start " << r << ' ';
        //cout  << ans(yes, b)  << " ans" <<  endl;
        //cout << "start " << l-1 << ' ';
        //cout << ans(no, b) << " ans " << endl;
        cout << ans(yes,b) - ans(no,b) << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}