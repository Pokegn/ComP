#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<lli> s, t, sf, tf;

lli rabin_karp() {
    const int p = 2000000009; 
    const int m = 1500000527;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i]) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i]) * p_pow[i]) % m; 

    lli occurrences = 0;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences++;
    }
    return occurrences;
}


void solve(){
    lli n, w; cin >> n >> w;
    tf = vector<lli>(n);
    sf = vector<lli>(w);

    forn(i, 0, n){
        cin >> tf[i];
    }
    forn(i, 0, w) cin >> sf[i];

    if(w == 1){
        cout << n << nl;
        return;
    }
    if(n<w){
        cout << 0 << nl;
        return; 
    }

    t = vector<lli>(n-1);
    s = vector<lli>(w-1);
    forn(i, 0, n-1){
        t[i] = tf[i+1] - tf[i] + 1e9;
    }
    forn(i, 0, w-1){
        s[i] = sf[i+1] - sf[i] + 1e9;
    }

    // for(auto x : t){
    //     cout << x << ' ';
    // }
    // cout << nl;
    // for(auto x : s) cout << x << ' ';
    
    cout << rabin_karp() << nl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    while(t--) solve();
    return 0;
}