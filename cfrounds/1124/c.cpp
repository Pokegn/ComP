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

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];

    if(k == 1){
        ll stot = 0;
        rep(i, 0, n) stot+=a[i];
        cout << stot << endl;
        return;
    }


    int li = k-1;
    int ri = (n-1)-(k-1);
    ll otrasuma = 0;
    if(li <= ri){
        ll m = n;
        set<int> idxs;
        vector<ll> b;
        rep(i, 0, k-1) idxs.insert(i);
        rep(i, 0, k-1) idxs.insert(n-k+1+i);
        for(auto idx: idxs) b.push_back(a[idx]);
    
        //2k-2 weones >= k-1 entonces de aqui agarro k-1 > 0

        rep(i, k-1, n-k+1) otrasuma += a[i];

    
        n = sz(b);
        swap(a, b);
        li = k-1;
        ri = (n-1)-(k-1);
    }

    // cout << otrasuma << ' ' << "XD ";
    // for(auto x: a) cout << x << ' ';
    // cout << endl;
    
    minheap<ll> pq;
    ll suma = 0;
    ll rem = n;
    ll curr = 0;

    while(rem >= k){
        suma += max(a[li], a[ri]);
        li++;
        ri--;
        rem--;
    }

    cout << suma + otrasuma << endl;
    return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}