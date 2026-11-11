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

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string s, int lim = 256){ //or vector<int>
        s.push_back(0); int n = sz(s), k = 0, a, b;
        vi x(all(s)), y(n), ws(max(n, lim));
        sa = lcp = y, iota(all(sa), 0);
        for(int j = 0, p = 0; p<n; j = max(1, j*2), lim = p){
            p = j, iota(all(y), n-j);
            rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i-1];
            for(int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i-1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a+j] == y[b+j]) ? p-1 : p++;
        }
        for(int i=0, j; i < n-1; lcp[x[i++]] = k)
            for(k && k--, j = sa[x[i]-1]; s[i+k] == s[j+k]; k++);
    }
};

string substring_order_i(string s, vector<ll> &have, vector<ll> &lcp, vector<ll> &sa, ll k){
    int idx = 1;
    ll rem = k;
    while(rem > have[idx]) rem-=have[idx], idx++;

    ll sizee = rem + lcp[idx];

    return s.substr(sa[idx], sizee);
}

ll get_range(ll m, ll n, vector<ll> &cumcount, vector<ll> &cumhave, vector<ll> &lcp){
    auto it = lower_bound(cumhave.begin(), cumhave.end(), m);
    int idx = (it == cumhave.end() ? n : (it-cumhave.begin())); //idx es el indice en el que esta el coso
    ll extra = m - cumhave[idx-1] - 1;

    //idx es el indice de sa en el que estoy
    //quiero el rango en el que esta el m-esimo cabron distinto
    //extra es cuantos enfrente estoy del primer unico
    //el primer unico es lcp[idx] indexado en 0

    ll count = cumcount[idx-1]; //cuantos no unicos hay antes

    count += lcp[idx] + extra; //les agrego los de ahorita en los que estoy

    ll temp;

    temp = idx+1;
    ll maxadd = lcp[idx]+extra;
    while(temp<= n && maxadd > 0){
        maxadd = min(maxadd, (ll)lcp[temp]);
        count += maxadd;
        temp++;
    }
    return count+1;
}

void solve(){
    string s; cin >> s;
    ll n = sz(s);
    ll k; cin >> k;
    auto SuffixArr = SuffixArray(s);
    vector<ll> sa, lcp;
    for(auto x: SuffixArr.sa) sa.push_back(x);
    for(auto x: SuffixArr.lcp) lcp.push_back(x);

    vector<ll> have(n+1, 0);
    rep(i, 1, n+1){
        have[i] = n - sa[i] - lcp[i];
    }
    vector<ll> cumhave(n+1, 0);
    rep(i, 1, n+1) cumhave[i] = cumhave[i-1] + have[i];
    
    ll tothave = 0;
    rep(i, 1, n+1) tothave+=have[i];
    
    vector<ll> cumcount(n+1, 0);
    rep(i, 1, n+1){
        cumcount[i]  = cumcount[i-1] + n - sa[i];
    }
    
    ll l = 1, r = tothave;
    while(r - l > 1){
        ll m = l + (r-l)/2;
        
        ll left = get_range(m, n, cumcount, cumhave, lcp); //quiero el rango que cubre esa m
        ll right = get_range(m+1, n, cumcount, cumhave, lcp) - 1;
        
        if(k < left){ //m demasiado grande
            r = m;
            continue;
        }
        if(right < k){ //m demasiado peque
            l = m+1;
            continue;
        }
        l = r = m;
    }
    cout << substring_order_i(s, have, lcp, sa, l) << endl;
    return;
}


int main(){
    // cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}