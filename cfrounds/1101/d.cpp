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

using namespace std;

int n;
vector<int> a;
vector<int> movs;

void ToH(vector<int> quieroMover, int s_rod, int d_rod, int a_rod){
    // If there's only one disk
    int sz = quieroMover.size();
    if(sz == 0) return;
    if (sz == 1) {
        // Print the move for the single disk
        movs.push_back(quieroMover[0]);
        movs.push_back(s_rod);
        movs.push_back(d_rod);
        return;
    }

    // If there are more than one disks
    // Call the towerOfHanoi function to move n-1 disks from
    // the source rod to the auxiliary rod using the
    // destination rod
    vector<int> moverIntermedio;
    int cuantosmuevo = sz-1 - a[quieroMover[sz-1]];
    for(int i = 0; i < cuantosmuevo; i++) moverIntermedio.push_back(quieroMover[i]);
    ToH(moverIntermedio, s_rod, a_rod, d_rod);
    //towerOfHanoi(n - 1, s_rod, a_rod, d_rod);

    // Print the move for the nth disk from the source rod
    // to the destination rod
    movs.push_back(quieroMover[sz-1]);
    movs.push_back(s_rod);
    movs.push_back(d_rod);
    // cout << movs.size() << endl;
    // return;

    if(cuantosmuevo != sz-1){
        ToH(moverIntermedio, a_rod, s_rod, d_rod);
        vector<int> restantes; rep(i, 0, sz-1) restantes.push_back(quieroMover[i]);
        ToH(restantes, s_rod, d_rod, a_rod);
    } 
    else{
        vector<int> restantes; rep(i, 0, sz-1) restantes.push_back(quieroMover[i]);
        ToH(restantes, a_rod, d_rod, s_rod);
    }
    // Call the towerOfHanoi function to move n-1 disks from
    // the auxiliary rod to the destination rod using the
    // source rod
    
}

void solve(){
    cin >> n;

    movs = vector<int> (0);
    a = vector<int> (n+1, 0); rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1){
        if(a[i] >= i){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    vector<int> orig(n);
    rep(i, 0, n) orig[i] = i+1;

    // Call the Tower of Hanoi function
    ToH(orig, 1, 3, 2);

    int sz = (movs.size())/3;
    cout << sz << endl;
    for(int i = 0; i < movs.size(); i+=3){
        cout << movs[i] << ' ' << movs[i+1] << ' ' << movs[i+2] << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}