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
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> oc;
    vector<pair<int, char>> nums;
    vector<char> ans;
    rep(i, 0, n){
        oc[s[i]]++;
    }
    nums.push_back({oc['R'], 'R'});
    nums.push_back({oc['G'], 'G'});
    nums.push_back({oc['B'], 'B'});
    sort(all(nums));
    if(nums[0].fi > 0) cout << "BGR" << endl;
    else{
        if(nums[1].fi == 0){
            cout << nums[2].se << endl;
            return;
        }
        if(nums[1].fi > 1){
            cout << "BGR" << endl;
            return;
        }
        if(nums[2].fi == 1){
            cout << nums[0].se << endl;
            return;
        }
        ans.push_back(nums[0].se);
        ans.push_back(nums[1].se);
        sort(all(ans));
        for(auto c: ans) cout << c;
        cout << endl;
        return;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}