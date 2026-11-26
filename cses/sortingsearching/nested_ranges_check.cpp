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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n; cin >> n;
    ordered_set<pair<ll, int>> opened_ends;
    ordered_set<pair<ll, int>> closed_starts;
    vector<vector<ll>> a;
    vector<pair<ll,ll>> ranges(n+1);
    vector<ll> contains(n+1), is_contained(n+1);
    rep(i,1,n+1){
        int x,y; cin >> x >> y;
        a.push_back({x, -1, -y, i});
        a.push_back({y, 1, -x, -i});
        ranges[i] = {x,y};
    }

    sort(all(a));
    
    for(auto p: a){
        // std::cout << p[0] << ' ' << p[1] << ' ' <<p[2] << ' ';
        int idx;

        //calcular respuesta
        if(p[3] > 0){ //open
            idx = p[3];
            //en cuantos esta es opened_ends
            is_contained[idx] = sz(opened_ends) - opened_ends.order_of_key({ranges[idx].se, -1});
            // std::cout << "is_contained " << is_contained[idx] << ' ' << sz(opened_ends) << endl;
        }
        else{ //end
            idx = -p[3];
            //cuantos tiene es closed_starts
            contains[idx] = sz(closed_starts) - closed_starts.order_of_key({ranges[idx].fi, -1});
            // std::cout << "contains " << contains[idx] << ' ' << sz(closed_starts) << endl;
        }

        //actualizar
        if(p[3] > 0){ //open
            opened_ends.insert({ranges[idx].se, idx});
        }
        else{ //end
            closed_starts.insert({ranges[idx].fi, idx});
            opened_ends.erase(opened_ends.find_by_order(opened_ends.order_of_key({ranges[idx].se, idx})));
        }
    }

    // std::cout << sz(opened_ends) << ' ' << sz(closed_starts) << endl;

    rep(i, 1, n+1){
        std::cout << (contains[i] > 0 ? 1:0) << ' ';
    }
    std::cout << endl;
    rep(i, 1, n+1){
        std::cout << (is_contained[i] > 0 ? 1:0) << ' ';
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}