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
    string s; cin >> s;
    int n = sz(s);
    vi a(26, 0);
    rep(i, 0, n){
        a[(int)(s[i]-'A')]++;
    }
    char imp = 1;
    rep(i, 0, 26){
        if(imp == -1) continue;
        if(a[i]%2 == 1){
            if(imp == 1){
                imp = i + 'A';
            }
            else imp = -1;
        }
    }

    string extra = "";
    if(imp == -1){
        cout << "NO SOLUTION" << endl;
        return;
    }
    if(imp != 1){
        a[imp - 'A']--;
        extra += imp;
    }
    string ans = "";
    rep(i, 0, 26){
        rep(j, 0, a[i]/2) ans += (i+'A');
    }

    cout << ans << extra;
    reverse(all(ans));
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}