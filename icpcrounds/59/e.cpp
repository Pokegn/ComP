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

set<pii>::iterator addInterval(set<pii>& is, int L, int R) {
if (L == R) return is.end();
auto it = is.lower_bound({L, R}), before = it;
while (it != is.end() && it->first <= R) {
R = max(R, it->second);
before = it = is.erase(it);
}
if (it != is.begin() && (--it)->second >= L) {
L = min(L, it->first);
R = max(R, it->second);
is.erase(it);
}
return is.insert(before, {L,R});
}

void removeInterval(set<pii>& is, int L, int R) {
if (L == R) return;
auto it = addInterval(is, L, R);
auto r2 = it->second;
if (it->first == L) is.erase(it);
else (int&)it->second = L;
if (R != r2) is.emplace(R, r2);
}

void solve(){
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}