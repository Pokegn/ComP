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

set<int> cosos;

int numinarray(vector<int> &s){
    int ans = 0;
    int sz = s.size();
    map<int, int> vis;
    rep(i, 0, sz){
        cosos.insert(s[i]);
        if(vis[s[i]] == 0){
             ans++;
        }
        vis[s[i]]++;
    }
    return ans;
}

void solve(){
    cosos.clear();
    int n, k; cin >> n >> k;
    vi a(n); rep(i, 0, n) cin >> a[i];

    int nums = numinarray(a);

    if(nums > k){
        cout << -1 << endl;
        return;
    }
    else{
        cout << k*n << ' ';
        rep(i, 0, n){
            for(auto val: cosos){
                cout << val << ' ';
            }
            //agrego (k-nums)
            rep(j, 0, k-nums){
                cout << 1 << ' ';
            }
        }
        cout << endl;
        return;
    }
    return;
    // rep(i, 0, n){
    //     if(i+k-1 >= n) continue;
    //     vi b(k);
    //     rep(j, 0, k){
    //         b[j] = a[i+j];
        // }
        // //cout << numinarray(b) << endl;
    
        // if(numinarray(b) == nums){
        //     int finalsz = k + (n-k)*k;
        //     cout << (k*(n-k+1)) << endl;
        //     rep(j, 0, n-k+1){
        //         rep(l, 0, k){
        //             cout << b[l] << ' ';
        //         }
        //     }
        //     cout << endl;
        //     return;
        // }      
    // }

    // cout << -1 << endl;
    // return;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}