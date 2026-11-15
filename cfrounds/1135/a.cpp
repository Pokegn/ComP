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


int m = 1e3+1;
vector<bool> is_prime(m+1, true);
vector<int> primes;
vector<int> minprime(m, -1);
    

void solve(){
    int n; cin >> n;
    if(n <= 3){
        cout << -1 << endl;
        return;
    }
    cout << 4 << ' ' << 3 << ' ' << 2 << ' ' << 1 << ' ';
    rep(i, 5, n+1){
        cout << i << ' ';
    }
    cout << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i] && (long long)i * i <= m) {
            for (int j = i * i; j <= m; j += i){
                if(minprime[j] == -1) minprime[j] = i;
                is_prime[j] = false;
            }
        }
    }
    for(int i=2; i<=m; i++){
        if(is_prime[i]) primes.push_back(i);
    }

    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}