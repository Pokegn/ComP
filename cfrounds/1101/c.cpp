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

ll n;
ll seats, tables; 
string s;

template<class F>
int ternSearch(int a, int b, F f) {
    assert(a <= b);
    while (b - a >= 5) {
        int mid = (a + b) / 2;
        if (f(mid) < f(mid+1)) a = mid; // (A)
        else b = mid+1;
    }
    rep(i,a+1,b+1) if (f(a) < f(i)) a = i; // (B)
    return a;
}

ll iters(ll m){
    ll iter = 0; // iteraciones
    ll ints = 0; // cuantas Es son I
    ll curr = 0; //el balanceo
    ll taken = 0; //mesas tomadas
    rep(i, 0, n){
        if(s[i] == 'A'){
            if(ints < m){
                ints++;
                if(taken == tables) continue;
                taken++;
                curr += seats-1;
            }
            else{
                if(curr == 0) continue;
                curr--;
            }
        }
        if(s[i] == 'I'){
            if(taken == tables) continue;
            taken++;
            curr += seats-1;
        }
        if(s[i] == 'E'){
            if(curr == 0) continue;
            curr--;
        }
        iter++;
    }
    return iter;
}

void solve(){
    cin >> n >> tables >> seats;
    cin >> s;
    ll ans = 0;
    ll es = 0;
    rep(i, 0, n) if(s[i] == 'A') es++;
    //ll l = 0, r = es;
    ans = ternSearch(0, es, iters);
    cout << iters(ans) << endl;
    return;
    for(ll m = 0; m <= es; m++){
    //while(l < r){
        //ll m = (l+r)/2; //cuantos los asigno a nuevo
        ll iter = 0; // iteraciones
        ll ints = 0; // cuantas Es son I
        ll curr = 0; //el balanceo
        ll taken = 0; //mesas tomadas
        rep(i, 0, n){
            if(s[i] == 'A'){
                if(ints < m){
                    ints++;
                    if(taken == tables) continue;
                    taken++;
                    curr += seats-1;
                }
                else{
                    if(curr == 0) continue;
                    curr--;
                }
            }
            if(s[i] == 'I'){
                if(taken == tables) continue;
                taken++;
                curr += seats-1;
            }
            if(s[i] == 'E'){
                if(curr == 0) continue;
                curr--;
            }
            iter++;
        }
        ans = max(ans, iter);
        //cout << iter << ' ';
    }
    //cout << endl;
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}