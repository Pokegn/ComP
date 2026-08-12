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
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) a[i]*=2;
    sort(all(a));

    pair<ll, ll> ans = {0,0};
    for(int i = n-1; i>=0; i--){
        ll grande = a[i]/2;
        //cuantos hay que 2*x > grande
        auto it_menor = upper_bound(all(a), grande);
        int no_jalan = (it_menor - a.begin()); //cuantos no jalan

        //count si jalan
        int count = i+1 - no_jalan;
        
        int idx = no_jalan; //indice del mayor q jala
        if(idx > 0){
            if((a[idx])/2 + (a[idx-1])/2 > grande){
                //cout << "si";
                count++;
            } 
        }

        if(count > ans.fi) ans = {count, i};
        //cout << no_jalan << ' ' << count << ' ' << idx << endl;
    }
    if(ans.fi < 3){
        cout <<0 << endl;
        return;
    }
    cout << ans.fi << ' ';

    for(int i = ans.se; i>= ans.se - ans.fi + 1; i--){
        cout << a[i]/2 << ' ';
    }
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}
