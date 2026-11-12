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
    vi freq(26, 0);
    rep(i, 0, n) freq[(int)(s[i]-'A')]++;
    rep(i, 0, 26){
        if(freq[i] > (n+1)/2){
            cout << -1 << endl;
            return;
        }
    }

    char before = '%';
    string ans = "";
    rep(i, 0, n){
        int mini = 100;
        int must = -1;
        rep(j, 0, 26){
            if(before == 'A'+j) continue;
            if((n-i)%2 == 1 && freq[j] == ((n-i)+1)/2) must = j;
            if(freq[j] > 0) mini = min(mini, j);
        }
        if(must != -1){
            ans += (char)('A'+must);
            before =  (char)('A'+must);
            freq[must]--;
        }
        else{
            ans += (char)('A'+mini);
            before =  (char)('A'+mini);
            freq[mini]--;
        }
    }
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