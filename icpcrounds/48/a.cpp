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

vector<int> a;
int movs;

void move(int i, int j){ //move from i to j
    if(i == 1){
        move(3, 5);
        move(3, j);
        return;
    }
    if(i == 2){
        move(3, 4);
        move(3, j);
        return;
    }
    movs++;
    cout << i-2 << ' ' << j-2 << endl;
    int x = a[i], y = a[i-1], z = a[i-2];
    rep(k, i+1, j+1) a[k-3] = a[k];
    a[j] = x; a[j-1] = y; a[j-2] = z;
    return;
}

void solve(){
    int n; cin >> n;
    a = vector<int> (n+1); rep(i, 1, n+1) cin >> a[i];

    // move(3,4);
    // rep(i, 1, n+1) cout << a[i] << ' ';
    // return;
    cout << 5000 << endl;
    movs = 0;
    //pos = vector<int> (6);
    //rep(i, 1, n+1) rep(j, 1, 6) if(a[i] == j) pos[j] = i;

    for(int i = n; i>=5; i--){
        int idx = i;
        rep(j, 1, n+1) if(a[j] == i) idx = j;

        move(idx, i);
        
    }

    int xd;
    while(!(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)){
        xd = rand();
        if(xd%2 == 0){
            move(3, 4);
        }
        else{
            move(3,5);
        }
    }
    rep(i, movs, 5000) cout << 1 << ' ' << 1 << endl;
    // rep(i, 1, n+1) cout << a[i] << ' ';
    // cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}