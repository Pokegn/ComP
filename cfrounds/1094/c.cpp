#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_multiset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

ll xd(ll i, ll j){
    return i*(1<<(30))+j;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n+1,0); rep(i, 1, n+1) cin >> a[i];
    unordered_map<ll, ll> ans;
    unordered_map<ll, ll> median;
    for(int i = 1; i<n+1; i++){
        ordered_multiset<ll> X;
        for(int j = i; j<n+1; j++){
            X.insert(a[j]);
            if((j-i)%2 == 0){
                median[xd(i,j)] = *X.find_by_order(((j-i)/2));
            }
        }
    }

    //cout << median[{1, 1}] << ' ' << median[{1,2}] << ' ' << median[{1,3}] << endl;


    for(int last = 1; last<=n; last++){
        for(int first = last; first >=1; first-=2){
            // vector<ll> lista;
            // rep(i, first, last+1) lista.push_back(a[i]);
            // sort(all(lista));
            // int len = lista.size();
            ll media = median[xd(first, last)];
            //= lista[(int)(len/2)]; //creo 
            if(first == 1){
                ans[xd(last, media)] = max(ans[xd(last, media)], (ll)1);
            }
            else{
                if(ans[xd(first-1, media)] > 0) ans[xd(last, media)] = max(ans[xd(last, media)], ans[xd(first-1, media)]+1);
            }
        }
    }
    ll anss = 1;
    for(int i = 1; i<=n; i++){
        anss = max(anss, ans[xd(n, a[i])]);
    }
    cout << anss << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}