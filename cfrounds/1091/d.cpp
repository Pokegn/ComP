#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i, 0, n) cin >> a[i];
    vector<int> idx(k); rep(i, 0, k) cin >> idx[i];
    rep(i, 0, k) idx[i]--;

    int count = 1;
    int col = a[idx[0]]; //color bueno
    int izq = 0, der = n-1;
    while(izq < n && a[izq] == col) izq++;
    while(der > -1 && a[der] == col) der--; //donde empiezo y termino
    
    vector<int> idxx; int curr = 0;
    //cout << izq << ' ' << der << ' ' << ' ' ;
    rep(i, izq, der+1){
        if(i > izq && a[i]!=a[i-1]) count++;
        while(curr < k && idx[curr] < i) curr++;
        if(curr < k && idx[curr] == i) idxx.push_back(count);
    }

    int left = 0, right = 0;
    rep(i, 1, idx[0]+1){
        if(a[i] != a[i-1]) left++;
    }
    rep(i, idx[k-1]+1, n){
        if(a[i] != a[i-1]) right++;
    }
    if(left>0 && left%2 == 0) left--;
    if(right>0 && right%2 == 0) right--;
    int ans = count/2; if(count%2 == 1) ans++;
    cout << count << ' ';
    ans = max(ans, right);
    ans = max(ans, left);
    if(ans%2 == 1) ans++;
     //cout << ans << endl;
     //return;

    rep(i, 1, idxx.size()){
        ans = max(ans, abs(idxx[i]-idxx[i-1]));
    }
    cout << ans << endl;
    // for(auto i: idxx){
    //     cout << i << ' ';
    //     mini = min(mini, abs(i-(count/2)));
    // }
    // //cout << "m" << ' ' << mini << ' ';
    // int ans = count/2+1;
    // if(mini != 0) ans++;
    // //ans+=mini;



    // vector<int> newa;
    // vector<int> newidx;
    // int curridx = 0;
    // newa.push_back(a[0]);
    // if(idx[0] == curridx){
    //     newidx.push_back(0);
    //     curridx++;
    // }
    // rep(i, 1, n){
    //     while(i < n && a[i] == a[i-1]){
    //         if(idx[curridx] == i){
    //             newidx.push_back(newa.size()-1);
    //             curridx++;
    //         }
    //         i++;
    //     }
    //     if(idx[curridx] == i){
    //         newa.s
    //     }

    // }


    
    // int l = 0; int r = k-1;
    
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}