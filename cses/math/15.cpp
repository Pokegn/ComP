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

vlli fact(21);

ll getk(vlli perm, ll n){
    ll count; ll ans = 1;
    for(int i=0; i<n; i++){
        count = 0;
        for(int j=i+1; j<n; j++){
            if(perm[i] > perm[j]) count++;
        }
        ans+= count*fact[n-i-1];
    }
    return ans;
}

void getperm(vlli &perm, ll n, ll k){
    k--;
    vector<int> used(21, 0);
    ll saltos = 0;
    for(int i=0; i<n; i++){
        saltos = k/fact[n-i-1];
        //cout << i << ' ' << saltos << endl;
        //for(auto u:used) cout << u << ' ';
        //cout << endl << endl;
        int pos = 1;
        while(used[pos]) pos++;
        while(saltos>0){
            while(used[pos]) pos++;
            saltos--;
            pos++;
        }
        while(used[pos]) pos++;
        perm[i] = pos;
        used[pos] = 1;
        k%=fact[n-i-1];
    }
    return;
}

void solve(){
    int number; cin >> number;
    if(number == 1){
        ll n, k; cin >> n >> k;
        vector<ll> perm(n, 0);
        getperm(perm, n, k);
        for(auto p: perm) cout << p << ' ';
        cout << endl;
        return;
    }
    else{
        ll n; cin >> n;
        vector<ll> perm(n);
        for(int i=0; i<n; i++) cin >> perm[i];
        ll k = getk(perm, n);
        cout << k << endl;
        return;
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;

    fact[0] = fact[1] = 1;
    for(ll i=2; i<21; i++){
        fact[i] = fact[i-1]*i;
    }

    while(t--) solve();
    return 0;
}