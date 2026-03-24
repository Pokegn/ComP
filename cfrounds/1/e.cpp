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

vector<bool> vis;
vector<int> ans;

int smallestcoso(string s){
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n-1];
}



void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    ans = vector<int> (n, 0);
    ll resp = 0;

    rep(i, 0, q){
        string s;
        ans = vector<int> (n, 0);
        int l, r; cin >> l >> r;
        l--; r--;
        string pre = "";
        rep(j, l, r+1){
            pre += s[j];
            int cos = smallestcoso(pre);
            cout << cos << ' ';
            if(cos == pre.length()) ans[pre.length()] = 1;
            else ans[pre.length()] = 1+ans[pre.length()-cos];
            resp+= ans[pre.length()];
        }
    }
    cout << resp << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}