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
typedef vector<long long> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){ 
    int n; cin >> n;
    string s; cin >> s;

    vi lasti(10, -1);
    vector<vi> last(n, vi(10));
    for(int i = n-1; i>=0; i--){
        int c = (s[i] - '0');
        lasti[c] = i;
        rep(j, 0, 10){
            last[i][j] = lasti[j];
        }
    }

    //la ultima vez que habia cierto numero hacia adelante
    vi cum(n+2, 0);//esto es cuanto va cambiando lo que le quito
    vi add(n+2, 0);

    ll ans = 0;
    rep(i, 0, n){ //intento empezar aqui
        int l1, l2 ,l3;
        l3 = -1;
        l1 = last[i][2];
        if(l1 != -1) l2 = last[l1][0];
        if(l2 != -1) l3 = last[l2][2];

        int l = l3;
        if(l == -1) continue;
        int n5 = last[l][5];
        int n6 = last[l][6];
        if(n6 == -1) n6 = n;
        if(n5 == -1 || n6 < n5) continue;
        add[i] += (n6-n5);
        // add[n6+1] -= (n6-n5);
        cum[n5]++;
        cum[n6]--;
        // add[n6+1] -= (n6-n5);
        // ans += n6-n5;
    }

    vi a(n, 0);
    // rep(i, 0, n){
    //     cout << cum[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, n){
    //     cout << add[i] << ' ';
    // }
    // cout << endl;

    int quitomenos = 0;
    rep(i, 0, n){
        // cout << quitomenos << ' ';
        a[i] = add[i];
        if(i > 0) a[i] += a[i-1];
        a[i] -= quitomenos;
        quitomenos += cum[i];
    }
    // cout << endl;
    // rep(i, 0, n){
    //     cout << a[i] << ' ';

    // }
    // cout << endl;

    rep(i, 0, n){
        cout << (ll)(i+1)*((ll)n-i) - (ll)a[i] << ' ';
    }
    cout << endl;

    // cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}