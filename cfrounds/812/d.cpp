#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    int m = (1<<n);

    int score = 0;
    vector<int> curr(m);
    iota(all(curr), 1);
    while(score < n-1){
        vector<int> newcurr;
        int sz = curr.size();
        rep(i, 0, sz/4){
            cout << "? " << curr[4*i] << ' ' << curr[4*i+2] << endl;
            int res1; cin >> res1;
            if(res1 == 0){
                cout << "? " << curr[4*i+1] << ' ' << curr[4*i+3] << endl;
                int res2; cin >> res2;
                if(res2 == 1) newcurr.push_back(curr[4*i+1]);
                else newcurr.push_back(curr[4*i+3]);
            }
            if(res1 == 2){
                cout << "? " << curr[4*i+1] << ' ' << curr[4*i+2] << endl;
                int res2; cin >> res2;
                if(res2 == 2) newcurr.push_back(curr[4*i+2]);
                else newcurr.push_back(curr[4*i+1]);
            }
            if(res1 == 1){
                cout << "? " << curr[4*i] << ' ' << curr[4*i+3] << endl;
                int res2; cin >> res2;
                if(res2 == 2) newcurr.push_back(curr[4*i+3]);
                else newcurr.push_back(curr[4*i]);
            }
        }
        curr = newcurr;
        score+=2;
    }
    if(score == n){
        cout << "! " << curr[0] << endl;
        return;
    }
    cout << "? " << curr[0] << ' ' << curr[1] << endl;
    int res; cin >> res;
    if(res == 1) cout << "! " << curr[0] << endl;
    else cout << "! " << curr[1] << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}