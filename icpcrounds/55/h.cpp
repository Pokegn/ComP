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

void solve(){
    int n; cin >> n;
    if(n<=3){
        cout << "NO"<< endl;
        return;
    }
    cout << "YES" << endl;
    if(n%4 == 0){
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
        for(int i = 5; i <= n; i+=2){
            cout << i << " - " << i+1 << " = -1" << endl;
        }
        int k = n - 4;
        rep(i, 0, k/4) cout << "-1 - -1 = 0" << endl;
        rep(i, 0, k/4 - 1) cout << "0 - 0 = 0" << endl; 
        if(n>=8)cout << "24 - 0 = 24" << endl;
        return;       
    }
    if(n%4 == 1){
        cout << "3 - 2 = 1" << endl;
        cout << "1 + 4 = 5" << endl;
        cout << "5 * 5 = 25" << endl;
        cout << "25 - 1 = 24" << endl;
        for(int i = 6; i <= n; i+=2){
            cout << i << " - " << i+1 << " = -1" << endl;
        }
        int k = n - 5;
        rep(i, 0, k/4) cout << "-1 - -1 = 0" << endl;
        rep(i, 0, k/4 - 1) cout << "0 - 0 = 0" << endl; 
        if(n>=8)cout << "24 - 0 = 24" << endl;
        return;   
    }
    if(n%4 == 2){
        cout << "2 - 1 = 1" << endl;
        cout << "6 - 5 = 1" << endl;
        cout << "1 + 1 = 2" << endl;
        cout << "3 * 4 = 12" << endl;
        cout << "12 * 2 = 24" << endl;
        for(int i = 7; i <= n; i+=2){
            cout << i << " - " << i+1 << " = -1" << endl;
        }
        int k = n - 6;
        rep(i, 0, k/4) cout << "-1 - -1 = 0" << endl;
        rep(i, 0, k/4 - 1) cout << "0 - 0 = 0" << endl; 
        if(n >=8)cout << "24 - 0 = 24" << endl;
        return;   
    }
    if(n%4 == 3){
        cout << "1 + 3 = 4" << endl;
        cout << "4 + 4 = 8" << endl;
        cout << "8 + 5 = 13" << endl;
        cout << "13 + 6 = 19" << endl;
        cout << "19 + 7 = 26" << endl;
        cout << "26 - 2 = 24" << endl;
        for(int i = 8; i <= n; i+=2){
            cout << i << " - " << i+1 << " = -1" << endl;
        }
        int k = n - 7;
        rep(i, 0, k/4) cout << "-1 - -1 = 0" << endl;
        rep(i, 0, k/4 - 1) cout << "0 - 0 = 0" << endl; 
        if(n >= 8) cout << "24 - 0 = 24" << endl;
        return;   
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}