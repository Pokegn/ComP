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
    vector<ll> a(n); rep(i,0,n) cin >> a[i];
    a.push_back(0);

    ll count = 0;
    rep(i,0,n){
        if(a[i] < 0) count++;
    }

    int mov = 0;
    if(count == 0){
        cout << mov << endl;
        return;
    }
    rep(i,1,n){
        if(a[i] >= 0) continue;
        int prev = 1, nex = 0;
        if(a[i-1] < 0) prev++;
        if(a[i+1] < 0) prev++;

        if(a[i] < 0){
            a[i-1] += a[i];
            a[i+1] += a[i];
            a[i] *= -1;
        }

        if(a[i-1] < 0) nex++;
        if(a[i+1] < 0) nex++;
        count += nex-prev;
        mov++;
        if(count == 0){
            cout << mov << endl;
            return;
        }
    }

    rep(i,1,n){
        if(a[i] >= 0) continue;
        int prev = 1, nex = 0;
        if(a[i-1] < 0) prev++;
        if(a[i+1] < 0) prev++;

        if(a[i] < 0){
            a[i-1] += a[i];
            a[i+1] += a[i];
            a[i] *= -1;
        }

        if(a[i-1] < 0) nex++;
        if(a[i+1] < 0) nex++;
        count += nex-prev;
        mov++;
        if(count == 0){
            cout << mov << endl;
            return;
        }
    }

    rep(i,1,n){
        if(a[i] >= 0) continue;
        int prev = 1, nex = 0;
        if(a[i-1] < 0) prev++;
        if(a[i+1] < 0) prev++;

        if(a[i] < 0){
            a[i-1] += a[i];
            a[i+1] += a[i];
            a[i] *= -1;
        }

        if(a[i-1] < 0) nex++;
        if(a[i+1] < 0) nex++;
        count += nex-prev;
        mov++;
        if(count == 0){
            cout << mov << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}