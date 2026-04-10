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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    vector<int> p(n+1, 0);
    rep(i, 1, n+1) cin >> p[i];

    minheap<int> pq;
    int next;
    rep(i, 1, n+1){
        while(!pq.empty() && pq.top() <= i) pq.pop();
        if(pq.empty()) next = n+1;
        else next = pq.top();

        if(p[i] == -1){
            p[i] = next;
        }
        else{
            if(!pq.empty() && p[i] > pq.top()){
                cout << -1 << endl; return;
            }
            if(p[i] <= i){
                cout << -1 << endl; return;
            } 
        }
        pq.push(p[i]);
    }

    
    //rep(i, 0, n+1) cout << p[i] << ' '; cout << endl; 
    vector<int> freq(n+2, 0);
    rep(i, 1, n+1) freq[p[i]]++; 
    
    vector<int> mini(n+2, 1);
    rep(i, 2, n+2) mini[i] = mini[i-1] + freq[i-1];

    //for(auto x: freq) cout<<x << ' '; cout <<endl;
    //for(auto x: mini) cout<<x << ' '; cout <<endl;
    
    vector<int> god(n+1, 0);
    for(int i=n; i>=1; i--){
        god[i] = mini[p[i]];
        mini[p[i]]++;
    }

    rep(i, 1, n+1) cout << god[i] << ' ';
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}