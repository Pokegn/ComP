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

vector<int> ans(1000001);
const int n = 1000001;

void fill(){
    ans[1] = 0; //lose
    ans[2] = 0;
    for(int k =3; k<=100000; k++){
        ans[k] = 0;
        int mex = 0;
        map<int, int> m;
        for(int i = 1; 2*i<k; i++){
            m[ans[i]^ans[k-i]] = 1;
        }
        int idx = 0;
        while(m[idx] != 0) idx++;
        ans[k] = idx;
        // if(k > 8 && ans[k] == 0) cout << "lol " << k << endl;
    }
}


void solve(){
    int n; cin >> n;
    vector<int> ses = {1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362,
        365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222 };
    bool firstt = 1;
    for(auto x: ses) if(x == n) firstt = 0;
    if(firstt){
        cout << "first" << endl;
    }
    else cout << "second" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    // fill();
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}