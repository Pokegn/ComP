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

const int N = 1000000;
const int M = 1000000007;

int trie[N + 1][26];
int trie_pos;
bool final[N + 1];
ll ans[N+1];

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;
    while (k--) {
        string w;
        cin >> w;
        int node = 0;
        for (auto c : w) {
            int idx = c - 'a';
            if (trie[node][idx] == 0) {
                trie[node][idx] = ++trie_pos;
            }
            node = trie[node][idx];
        }
        final[node] = true;
    }

    ans[n] = 1;


    for(int i=n-1; i>=0; i--){
        ll curr = 0;
        rep(j, i, n){
            int idx = s[j] - 'a';
            curr = trie[curr][idx];
            if(curr == 0) break;
            if(final[curr]){
                ans[i] += ans[j+1];
                ans[i] %= 1000000007;
            } 
        }
    }
    
    cout << ans[0] << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}

