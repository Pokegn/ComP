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

ll count(ll n, ll mod, ll cong){ //n=7, mod=2, cong=0
    cong%=mod;
    ll r = n%mod;
    if(cong == 0){ //n = 1 mod 2 (r=1)
        return n/mod;
    }
    ll ret = 0;
    ret+=n/mod; //quiero la congruencia 0
    if(r>=cong) ret++;
    return ret;
}

ll last(ll n, ll mod, ll cong){
    cong%=mod;
    ll ans = (n/mod)*mod;
    ans+=cong;
    while(ans>n) ans-=mod;
    return ans;
}

void solve(){
    ll n, k; cin >> n >> k;
    if(n == 1 && k == 1){
        cout << 1 << endl;
        return;
    }

    ll remaining = n;
    ll mod = 2;
    ll congremove = 0;
    ll congstay = 1;
    ll remove, stay;
    ll actuallyremove;
    ll removed = 0;
    while(remaining > 1){
        remove = count(n, mod, congremove%mod);
        stay = count(n, mod, congstay%mod);

        if(removed+remove >= k){
            ll porquitar = k-removed; //quiero el porquitar-esimo numero con congruencia congremove
            //quiero el porquitar-esimo numero con congruencia igual a congremove
            ll ans = (mod)*(porquitar-1) + congremove%mod; //n/mod = 7/2 * 
            if(congremove%mod == 0) ans+=mod;
            cout << ans << endl;
            return;
        }

        remaining -= remove;
        removed += remove;
        //cout << mod << ' ' << congremove << ' ' << removed << endl;

        if(last(n, mod, congremove%mod) > last(n, mod, congstay%mod)){
            congremove = congstay+mod;
            congstay = congstay;
        }
        else{
            congremove = congstay;
            congstay = congstay+mod;
        }
        mod *= 2;
    }

    cout << min(congstay, congremove) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}