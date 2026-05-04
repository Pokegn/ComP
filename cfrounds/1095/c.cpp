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
    int n; cin >> n;
    vector<int> a(n); rep(i,0,n) cin >> a[i];
    vector<int> maxi(n);
    rep(i,0,n){
        if(a[i] == 1) maxi[i] = 0;
        //else if(a[i] == 0) maxi[i] = 0;
        else
        maxi[i] = (a[i]+1)/2 -1;
    }
    int l = 1; int r = n+1;
    while(l < r){
        int agarre = 0;
        int m = (l+r+1)/2;
        bool posible = true;
        vector<bool> tengo(n+2, false);
        vector<int> maxis;
        rep(i, 0, n){
            if(a[i] < m && tengo[a[i]] == false){ //m es mi mex
                tengo[a[i]] = true;
                //cout << "tengo " << a[i] << endl;
                continue;
            }
            else{
                maxis.push_back(maxi[i]);
                //cout << "maxis " << maxi[i] << endl;
            }
        }

        sort(all(maxis));
        int next = 0;
        rep(i, 0, maxis.size()){
            while(tengo[next] == true) next++;
            if(next >= m) break;
            if(maxis[i] < next){
                continue;
            }
            else{
                tengo[next] = true;
                next++;
            } 
        }

        rep(i, 0, m) if(!tengo[i]) posible = false;


        if(posible){
            // cout << "yei";
            l = m;
        }
        else{
            r = m-1;
        }
    }
    cout << l << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}