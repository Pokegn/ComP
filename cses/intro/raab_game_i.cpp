#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define endl '\n'
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    int a,b; cin >> a >> b;
    int c = n-a-b;
    //a mayores, b menores, c iguales
    if(c < 0){
        cout << "NO" << endl;
        return;
    }
    if(a+b > 0 && (a==0 || b==0)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vi ac, bc;


    rep(i, 1, c+1){
        ac.push_back(i);
        bc.push_back(i);
    }

    rep(i, c+1, c+1+b){
        ac.push_back(i);
        bc.push_back(i+a);
    }

    rep(i, c+1+b, c+1+a+b){
        ac.push_back(i);
        bc.push_back(i-b);
    }

    for(auto x: ac) cout << x << ' '; cout << endl;
    for(auto x: bc) cout << x << ' '; cout << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}