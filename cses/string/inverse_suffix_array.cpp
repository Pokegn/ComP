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
    vi sa(n+1); 
    rep(i, 1, n+1){
        cin >> sa[i];
        sa[i]--;
    } 
    sa[0] = n;

    vi a(n+1);
    rep(i, 0, n+1) a[sa[i]] = i;

    int curr = 0;
    vector<int> s(n+1);

    s[sa[1]+1] = 0; 
    
    rep(i, 1, n){
        if(a[sa[i]+1] < a[sa[i+1]+1]){
            s[sa[i+1]+1] = curr;
        }
        else{
            curr++;
            s[sa[i+1]+1] = curr;
        }
    }


    if(curr >= 26){
        cout << -1 << endl;
        return;
    }

    rep(i, 1, n+1){
        cout << (char)(s[i] + 'a');
    }
    cout << endl;
    return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}