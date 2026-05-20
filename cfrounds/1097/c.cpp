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
    string a,b; cin >> a >> b;
    vector<int> value(n,0);
    if(a[0] == '(') value[0]++;
    else value[0]--;
    if(b[0] == '(') value[0]++;
    else value[0]--;
    rep(i, 1, n){
        value[i] = value[i-1];
        if(a[i] == '(') value[i]++;
        else value[i]--;
        if(b[i] == '(') value[i]++;
        else value[i]--;
    }

    if(value[n-1]!=0){
        cout << "NO" << endl;
        return;
    }
    rep(i, 0, n){
        if(i%2 != 0){
            if(value[i]<0){
                cout << "NO" << endl;
                return;
            }
        }
        else{
            if(value[i]<=0){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}