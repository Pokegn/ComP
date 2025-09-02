#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    priority_queue<pair<lli, char>> pq;
    lli n; cin >> n;
    string s; cin >> s;
    vector<lli> a(26, 0);
    forn(i, 0, n){
        lli xd = s[i]-'a';
        a[xd]++;
    }
    forn(i, 0, 26){
        pq.push({a[i], (char)'a'+i});
    }

    string ans = "";
    lli sz = 0;
    while(sz < n){
        auto topo = pq.top();
        pq.pop();
        auto topo2 = pq.top();
        pq.pop();

        if(sz > 0 && ans[sz-1] == topo.second && topo2.first > 0){
            ans+=topo2.second;
            topo2.first--;            
        }

        else{
            ans+=topo.second;
            topo.first--;
        }

        pq.push(topo);
        pq.push(topo2);
        sz++;
    }

    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}