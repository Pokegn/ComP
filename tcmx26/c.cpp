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
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m); rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    vector<ll> lefta(n+1), leftb(m+1), righta(n+1), rightb(m+1);
    sort(all(a));
    sort(all(b));
    vector<ll> arang, brang;
    int l = 0, r = n-1;
    while(l < r){
        arang.push_back(a[r] - a[l]);
        l++; r--;
    }
    l = 0, r = m-1;
    while(l < r){
        brang.push_back(b[r] - b[l]);
        l++; r--;
    }

    vector<ll> asum(arang.size()+1,0), bsum(brang.size()+1,0);
    rep(i, 1, arang.size()+1) asum[i]=asum[i-1]+arang[i-1];
    rep(i, 1, brang.size()+1) bsum[i]=bsum[i-1]+brang[i-1];

    ll k = min(n, m);
    vector<pair<ll, ll>> ans(k+1);
    ans[0] = pair<ll, ll> {0,0};
    k = min(k, (ll)(n+m)/3);
    cout << k << endl;
    ll ai = 0, bi = 0;
    for(int i = 1; i<=k; i++){
        int ataken = ai*2 + bi;
        int btaken = ai + 2*bi;
        
        // cout << "xd " << i << endl;
        if(ai == arang.size()){
            if(ai*2+bi+1 <= n && ai + 2*bi + 2 <= m){
                bi++;
            }
            else{
                // cout << "Xd";
                ai--;
                bi+=2;
            }
            ans[i] = {ai, bi};
            continue;
        }
        if(bi == brang.size()){
            if(ai*2+bi+2 <= n && ai + 2*bi + 1 <= m){
                ai++;
            }
            else{
                ai+=2;
                bi--;
            }
            ans[i] = {ai, bi};
            continue;
        }
        if(arang[ai] > brang[bi]){
            if(ai*2+bi+2 <= n && ai + 2*bi + 1 <= m){
                ai++;
            }
            else if(ai*2+bi+1 <= n && ai + 2*bi + 2 <= m){
                bi++;
            }
            else if(ai*2+bi +3 <= n){
                bi--;
                ai+=2;
            }
            else if(bi*2 + ai + 3 <= m){
                ai--;
                bi+=2;
            }
            ans[i] = {ai,bi};
            continue;
        }
        else{
            if(ai*2+bi+1 <= n && ai + 2*bi + 2 <= m){
                bi++;
            }
            else if(ai*2+bi+2 <= n && ai + 2*bi + 1 <= m){
                ai++;
            }
            else if(ai*2+bi +3 <= n){
                bi--;
                ai+=2;
            }
            else if(bi*2 + ai + 3 <= m){
                ai--;
                bi+=2;
            }
            ans[i] = {ai,bi};
            continue;
        }
    }

    rep(i, 1, k+1){
        int aa = ans[i].first, bb = ans[i].second;
        cout << asum[aa] + bsum[bb] << ' ';
    }
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}