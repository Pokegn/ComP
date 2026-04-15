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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n;
    int q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, int> m;
    vector<int> reversem(n, 0);
    vector<int> a2 = a;
    sort(all(a2));
    int curr = 1;
    rep(i, 0, n){
        if(m[a2[i]] == 0){
            m[a2[i]] = curr;
            reversem[curr-1] = a2[i];
            curr++;
        }
    }
    vector<int> freq(n, 0);
    rep(i, 0, n){
        a[i] = m[a[i]]-1;
        freq[a[i]]++;
    } 
    vector<int> g;
    rep(i, 0, n) if(freq[i] > 580) g.push_back(i); //mas valor significa mas tiempo, menos memoria 
    vector<vector<int>> god(g.size(), vector<int>(n));
    rep(i, 0, g.size()){
        god[i][0] = (a[0] == g[i]);
        rep(j, 1, n){
            god[i][j] = god[i][j-1] + (a[j] == g[i]);
        }
    }

    rep(qq, 0, q){
        int l, r; cin >> l >> r; l--; r--;
        int comp = (r-l+1)/3;
        vector<int> ans;
        if(comp >= 580){
            rep(i, 0, god.size()){
                int freq = god[i][r];
                if(l > 0) freq-= god[i][l-1];
                if(comp < freq) ans.push_back(g[i]);
            }
        }
        else{
            vector<int> f(n, 0);
            set<int> putamadremarge;
            rep(i, l, r+1){
                f[a[i]]++;
                if(f[a[i]] > comp) putamadremarge.insert(a[i]);
            }
            for(auto FAAAAAA: putamadremarge) ans.push_back(FAAAAAA);
        }
        if(ans.size() == 0) cout << -1 << endl;
        else{
            for(auto x:ans) cout << reversem[x] << ' ';
            cout << endl;
        }
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}